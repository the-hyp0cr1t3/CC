/* Big int ops */
// References
// - https://github.com/knst/big_number
// - https://gist.github.com/ar-pa/957297fb3f88996ead11
// - https://github.com/dmkz/competitive-programming/blob/master/e-olymp.com/0317.cpp

// alternate: base = 26, grpsz = 6, base_char = 'a'
template<int base = 10, int grpsz = 9, char base_char = '0'>
struct BigInt {
    static constexpr auto t = []() {
        array<int, grpsz+1> p{1};
        int n = 0, m = 0;
        for(int i = 1; i <= grpsz; ++i) {
            p[i] = p[i-1] * base;
            if(p[i] <= 1000000) n = i;
        } m = p.back();
        return make_tuple(m, n, p);
    }();

    // more efficient with large base; should not exceed 1e9 (overflow)
    static constexpr int _mod = get<0>(t);                      // base^{grpsz}
    static constexpr int reduced_grpsz = get<1>(t);             // to avoid multiplication overflow
    static constexpr array<int, grpsz+1> pows = get<2>(t);      // _mod powers for base conversion
    static constexpr int karatsubaMinimalSize = 50;
    
    int sign{1};
    vector<int> d;
    
// ctors
    BigInt(int64_t number = 0) {
        sign = number < 0? number = -number, -1 : 1;
        while(number > 0) d.emplace_back(number % _mod), number /= _mod;
    }
    // _digits = MSB...LSB (not in groups of size grpsz); sign = -1 || 1
    BigInt(const vector<int>& _digits, int sign = 1): sign(sign) {
        d.reserve(sz(_digits)/grpsz + 1);
        for(int i = sz(_digits)-1, block = 0; i >= 0; i -= grpsz, block = 0) {
            for(int j = max(0, i-grpsz+1); j <= i; j++)
                block = block * base + _digits[j];
            d.emplace_back(block);
        } normalize();
    }
    BigInt(const string& s): BigInt(convert_string_to_vector(s), (s[0] == '-'? -1 : 1)) {}

    // does not handle overflow
    template<typename T, typename = enable_if_t<is_integral<T>::value>>
    explicit operator T() const {
        T res = 0;
        for(auto& _d: d)
            res = res * _mod + _d;
        return res * sign;
    }

// io
    string to_string() const {
        string s;
        if(is0()) s += base_char;
        else {
            for(auto res: d)
                for(int j = 0; j < grpsz; j++)
                    s += res % base + base_char, res /= base;
            while(s.size() and s.back() == base_char) s.pop_back();
            if(sign < 0) s += '-';
            reverse(s.begin(), s.end());            
        } return s;
    }

    friend istream& operator>>(istream& is, BigInt& number) { string s; is >> s; number = BigInt(s); return is; }
    friend ostream& operator<<(ostream& os, const BigInt& number) { return os << number.to_string(); }

// helpers
    inline bool is0() const noexcept { return !d.size(); }
    inline void normalize() noexcept {
        while(d.size() and !d.back()) d.pop_back();
        if(!d.size()) sign = 1;
    }
    static vector<int> convert_string_to_vector(const string& s) {
        vector<int> v; v.reserve(s.size());
        for(auto c: s) if(c != '-')
            v.emplace_back(c - base_char);
        return v;
    }

// compare
    int compare(const BigInt& o) const noexcept {
        if(sign != o.sign) return sign == 1? 1 : -1;
        if(sz(d) > sz(o.d)) return sign == 1? 1 : -1;
        if(sz(d) < sz(o.d)) return sign == 1? -1 : 1;
        for(int i = sz(d)-1; i >= 0; --i) {
            if(d[i] > o.d[i]) return sign == 1? 1 : -1;
            if(d[i] < o.d[i]) return sign == 1? -1 : 1;
        } return 0;
    }

    bool operator< (const BigInt& o) const noexcept { return compare(o) < 0; }
    bool operator> (const BigInt& o) const noexcept { return compare(o) > 0; }
    bool operator==(const BigInt& o) const noexcept { return compare(o) == 0; }
    bool operator<=(const BigInt& o) const noexcept { return compare(o) <= 0; }
    bool operator>=(const BigInt& o) const noexcept { return compare(o) >= 0; }
    bool operator!=(const BigInt& o) const noexcept { return compare(o) != 0; }

// operator overloads
    int operator[](size_t idx) const noexcept { return d[idx]; }
    BigInt operator-() const { BigInt res = *this; res.sign *= -1; return res; }
    BigInt abs() const { BigInt res = *this; res.sign *= res.sign; return res; }
    
    void increment() { 
        for(auto& _d: d) { if(++_d < _mod) return; _d = 0; }
        d.emplace_back(1);
    }
    void decrement() {
        if(is0()) { sign = -1; d.emplace_back(1); }
        else { for(auto& _d: d) { if(_d--) return normalize(); _d = _mod - 1; } }
    }
    
    BigInt& operator++() { sign > 0? increment() : decrement(); return *this; }
    BigInt& operator--() { sign > 0? decrement() : increment(); return *this; }
    BigInt operator++(int) { BigInt res = *this; ++*this; return res; }
    BigInt operator--(int) { BigInt res = *this; --*this; return res; }
    
    BigInt& operator+=(const int64_t num) {
        if(sign > 0 != num > 0) return *this -= BigInt(-num);
        if(num >= _mod) return *this += BigInt(num);
        int carry = num;
        for(int pos = 0; pos < sz(d) and carry; pos++) {
            d[pos] += carry;
            carry = d[pos] >= _mod;
            if(carry) d[pos] -= _mod;
        } if(carry) d.emplace_back(1);
        return normalize(), *this;
    }

    BigInt& operator+=(const BigInt& o) {
        if(sign != o.sign) return *this -= -o;
        d.resize(max(sz(d), sz(o.d)));
        int carry = 0;
        for(int pos = 0; pos < sz(d); pos++) {
            d[pos] += carry + (pos < sz(o.d)? o.d[pos] : 0);
            carry = d[pos] >= _mod;
            if(carry) d[pos] -= _mod;
        } if(carry) d.emplace_back(1);
        return *this;
    }

    BigInt& operator-=(const BigInt& o) {
        if(sign != o.sign) return *this += -o;
        if(o.abs() > abs()) return *this = -(o - *this);
        int carry = 0;
        for(int pos = 0; pos < sz(o.d) or carry; pos++) {
            d[pos] -= carry + (pos < sz(o.d)? o.d[pos] : 0);
            carry = d[pos] < 0;
            if(carry) d[pos] += _mod;
        } normalize();
        return *this;
    }

    BigInt operator+(const BigInt& o) const { BigInt res = *this; res += o; return res; }
    BigInt operator-(const BigInt& o) const { BigInt res = *this; res -= o; return res; }

    BigInt& operator*=(int num) {
        if(num < 0) sign = -sign, num = -num;
        if(num >= _mod) return *this *= BigInt(num), *this;
        int64_t rem = 0;
        for(auto& i : d) {
            rem += 1LL * i * num;
            int64_t div = rem / _mod;
            i = rem - div*_mod;
            rem = div;
        } if(rem > 0) d.emplace_back(rem);
        return normalize(), *this;
    }

    BigInt operator*(int num) const { BigInt res = *this; res *= num; return res; }
    BigInt operator*=(const BigInt& o) { return *this = *this * o; }

    BigInt operator*(const BigInt &o) const {
        vector<int64_t> U = convert_base<int64_t>(d, grpsz, reduced_grpsz);
        vector<int64_t> V = convert_base<int64_t>(o.d, grpsz, reduced_grpsz);
        int32_t _sz = max(sz(U), sz(V));
        _sz--; _sz |= _sz >> 1; _sz |= _sz >> 2; _sz |= _sz >> 4;
        _sz |= _sz >> 8; _sz |= _sz >> 16; _sz++;    // round up to next power of 2 >= size
        U.resize(_sz); V.resize(_sz);
        vector<int64_t> ret = karatsubaMultiply(U, V, 0, _sz);
        BigInt res; res.sign = sign * o.sign;
        res.d.reserve(sz(ret));
        for(int i = 0, carry = 0; i < sz(ret); i++) {
            int64_t cur = ret[i] + carry;
            res.d.emplace_back(cur % pows[reduced_grpsz]);
            carry = cur / pows[reduced_grpsz];
        } res.d = convert_base<int>(res.d, reduced_grpsz, grpsz); res.normalize();
        return res;
    }

    BigInt& operator/=(int num) {
        assert(num && "Divide by zero");
        if(num >= _mod) return *this /= BigInt(num);
        if(num < 0) sign = -sign, num = -num;
        int64_t rem = 0;
        for(int j = sz(d)-1; ~j; j--) {
            (rem *= _mod) += d[j];
            int64_t div = rem / num;
            d[j] = div;
            rem -= div * num;
        } normalize(); return *this;
    }

    int operator%(int num) const {
        assert(num && "Divide by zero");
        if(num < 0) num = -num;
        int64_t rem = 0;
        for(int i = sz(d)-1; i >= 0; i--)
            ((rem *= _mod) += d[i]) %= num;
        return rem * sign;
    }

    BigInt operator/(int num) const { BigInt res = *this; res /= num; return res; }
    BigInt& operator/=(const BigInt& o) { return *this = div_mod(o).first; }
    BigInt operator/(const BigInt& o) const { return div_mod(o).first; }
    BigInt& operator%=(const BigInt& o) { return *this = div_mod(o).second; }
    BigInt operator%(const BigInt& o) const { return div_mod(o).second; }
    BigInt operator^(const BigInt& o) const {   // exponentiate
        BigInt res{1}, A = *this, B = o;
        while(!B.is0()) {
            if(B % 2) res *= A;
            B /= 2; A *= A;
        } return res;
    }

// Misc.
    template<typename T> 
    static vector<T> convert_base(const vector<int>& v, int from_cnt, int to_cnt) {
        vector<T> res; int64_t cur = 0, have = 0;
        for(int i = 0; i < sz(v); i++) {
            cur += 1LL * pows[have] * v[i];
            have += from_cnt;
            while(have >= to_cnt) {
                res.emplace_back(cur % pows[to_cnt]);
                cur /= pows[to_cnt]; have -= to_cnt;
            }
        } res.emplace_back(cur); while(!res.empty() && !res.back()) res.pop_back();
        return res;
    }

    static inline vector<int64_t> karatsubaSum(const vector<int64_t>& V, int pos, int len) {
        vector<int64_t> res(len);
        for(int i = 0; i < len; i++)
            res[i] = V[i + pos] + V[i + len + pos];
        return res;
    }
 
    static vector<int64_t> karatsubaMultiply(const vector<int64_t>& U, const vector<int64_t>& V, int pos, int len) {
        vector<int64_t> res(len << 1);
        if(len <= karatsubaMinimalSize) {
            for(int i = 0; i < len; i++)
                for(int j = 0; j < len; j++)
                    res[i + j] += U[i + pos] * V[j + pos];
            return res;
        }
        int k = len >> 1;
        vector<int64_t> u1v1 = karatsubaMultiply(U, V, pos, k);
        vector<int64_t> u2v2 = karatsubaMultiply(U, V, pos+k, k);
        vector<int64_t> usum = karatsubaSum(U, pos, k);
        vector<int64_t> vsum = karatsubaSum(V, pos, k);
        vector<int64_t> usum_vsum = karatsubaMultiply(usum, vsum, 0, k);
        for(int i = 0; i < len; i++) {
            res[i] += u1v1[i];
            res[i + len] += u2v2[i];
            res[i + k] += usum_vsum[i] - u1v1[i] - u2v2[i];
        } return res;
    }

    pair<BigInt, BigInt> div_mod(const BigInt& o) const {
        assert(!o.is0() && "Divide by zero");
        pair<BigInt, BigInt> res;
        if(sz(o.d) == 1) {
            res = {*this / o.d[0], *this % o.d[0]};
            return res;
        }
        const int norm = _mod / (o.d.back() + 1);
        const BigInt a = *this * norm;
        const BigInt b = o * norm;
        const int sz_a = sz(a.d);
        const int sz_b = sz(b.d);
        BigInt q, r; q.d.resize(sz_a);
        for(int i = sz_a-1; i >= 0; i--) {
            r *= _mod; r += a.d[i];
            int s1 = sz(r.d) <= sz_b ? 0 : r.d[sz_b];
            int s2 = sz(r.d) <= sz_b-1 ? 0 : r.d[sz_b-1];
            int _d = (1LL * _mod * s1 + s2) / b.d.back();
            auto temp = b * _d;
            while(r < temp)
                r += b, --_d;
            r -= temp;
            q.d[i] = _d;
        }
        q.sign = a.sign * b.sign; r.sign = a.sign;
        q.normalize(); res = {move(q), r /= norm};
        return res;
    }
    
    friend BigInt gcd(BigInt A, BigInt B) { while(!B.is0()) { A %= B; swap(A, B); } return A; }
};

/*
#define sz(x) (int)x.size()
int main() {
    BigInt a, b;
    cin >> a >> b;
    cout << a + b;
    
    string s = "bcdeaszza";
    BigInt<26, 6, 'a'> x(s);
    
    a /= b;
    cout << gcd(a, b);
}
*/
// see (https://codeforces.com/problemset/submission/1144/103589811)
