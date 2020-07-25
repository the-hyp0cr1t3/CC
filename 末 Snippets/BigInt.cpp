// From [this](https://codeforces.com/contest/1144/submission/52126022) submission by [YouKn0wWho](https://codeforces.com/profile/YouKn0wWho)
struct bigint {
    using ll = long long;
    static constexpr ll base = 26*26*26*26;
    static constexpr ll base_digits = 4;
    vector<ll>  a; ll sign;
 
    bigint() : sign(1) {}
    bigint(ll v) {*this = v;}
    bigint(const string &s) {read(s);}
 
    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }
 
    void operator=(ll v) {
        sign = 1;
        if (v < 0) sign = -1, v = -v;
        a.clear();
        for (; v > 0; v = v / base)
            a.pb(v % base);
    }
 
    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;
            for (ll i = 0, carry = 0; i < (ll)max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (ll)res.a.size())
                    res.a.pb(0);
                res.a[i] += carry + (i < (ll)a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }
 
    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (ll i = 0, carry = 0; i < (ll)v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (ll)v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry) res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }
 
    void operator*=(ll v) {
        if (v < 0) sign = -sign, v = -v;
        for (ll i = 0, carry = 0; i < (ll)a.size() || carry; ++i) {
            if (i == (ll)a.size()) a.pb(0);
            ll cur = a[i] * v + carry;
            carry = cur / base;
            a[i] = cur % base;
        }
        trim();
    }
 
    bigint operator*(ll v) const {
        bigint res = *this;
        res *= v;
        return res;
    }
 
    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        ll norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());
        for (ll i = (ll)a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            ll s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            ll s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            ll d = (base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }
 
    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }
 
    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }
 
    void operator/=(ll v) {
        if (v < 0) sign = -sign, v = -v;
        for (ll i = (ll)a.size() - 1, rem = 0; i >= 0; --i) {
            ll cur = a[i] + rem * base;
            a[i] = cur / v;
            rem = cur % v;
        }
        trim();
    }
 
    bigint operator/(ll v) const {
        bigint res = *this;
        res /= v;
        return res;
    }
 
    ll operator%(ll v) const {
        if (v < 0) v = -v;
        ll m = 0;
        for (ll i = (ll)a.size() - 1; i >= 0; --i)
            m = (a[i] + m * base) % v;
        return m * sign;
    }
 
    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }
 
    bool operator<(const bigint &v) const {
        if (sign != v.sign) return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (ll i = (ll)a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }
 
    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }
 
    void trim() {
        while (!a.empty() && !a.back()) a.pop_back();
        if (a.empty()) sign = 1;
    }
 
    bool isZero() const {
        return a.empty() || (a.size() == 1 && a[0] == 0);
    }
 
    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }
 
    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }
 
    ll longValue() const {
        ll res = 0;
        for (ll i = (ll)a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }
 
    void read(const string &s) {
        sign = 1;
        a.clear();
        ll pos = 0;
        while (pos < (ll)s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-') sign = -sign;
            ++pos;
        }
        for (ll i = (ll)s.size() - 1; i >= pos; i -= base_digits) {
            ll x = 0;
            for (ll j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 26 + s[j] - 'a';
            a.pb(x);
        }
        trim();
    }
 
    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }
 
    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1) stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (ll i = (ll)v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('a') << v.a[i];
        return stream;
    }
 
    static vector<ll> karatsubaMultiply(const vector<ll> &a, const vector<ll> &b) {
        ll n = a.size();
        vector<ll> res(n + n);
        if (n <= 32) {
            for (ll i = 0; i < n; i++)
                for (ll j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }
        ll k = n >> 1;
        vector<ll> a1(a.begin(), a.begin() + k);
        vector<ll> a2(a.begin() + k, a.end());
        vector<ll> b1(b.begin(), b.begin() + k);
        vector<ll> b2(b.begin() + k, b.end());
        vector<ll> a1b1 = karatsubaMultiply(a1, b1);
        vector<ll> a2b2 = karatsubaMultiply(a2, b2);
        for (ll i = 0; i < k; i++) a2[i] += a1[i];
        for (ll i = 0; i < k; i++) b2[i] += b1[i];
        vector<ll> r = karatsubaMultiply(a2, b2);
        for (ll i = 0; i < (ll)a1b1.size(); i++) r[i] -= a1b1[i];
        for (ll i = 0; i < (ll)a2b2.size(); i++) r[i] -= a2b2[i];
        for (ll i = 0; i < (ll)r.size(); i++) res[i + k] += r[i];
        for (ll i = 0; i < (ll)a1b1.size(); i++) res[i] += a1b1[i];
        for (ll i = 0; i < (ll)a2b2.size(); i++) res[i + n] += a2b2[i];
        return res;
    }
 
    bigint operator*(const bigint &v) const {
        vector<ll> x(this->a.begin(), this->a.end());
        vector<ll> y(v.a.begin(), v.a.end());
        while (x.size() < y.size()) x.pb(0);
        while (y.size() < x.size()) y.pb(0);
        while (x.size() & (x.size() - 1))
            x.pb(0), y.pb(0);
        vector<ll> z = karatsubaMultiply(x, y);
        bigint res;
        res.sign = sign * v.sign;
        for (ll i = 0, carry = 0; i < (ll)z.size(); i++) {
            ll cur = z[i] + carry;
            res.a.pb(cur % base);
            carry = cur / base;
        }
        res.trim();
        return res;
    }
};
