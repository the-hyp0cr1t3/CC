template<class T>
struct frac {
    T num, den;
    frac(T num = 0, T den = 1): num(num), den(den) { reduce(); }
    explicit operator T() { return floor(*this); }
    operator std::pair<T, T>() { return {num, den}; }

    friend istream& operator>>(istream& is, frac& r) { T n, d; is >> n >> d; r = frac(n, d); return is; }
    friend ostream& operator<<(ostream& os, const frac& r) { return os << '(' << r.num << '/' << r.den << ')'; }

    static inline T abs(T x) { return x < 0? -x : x; }
    static T gcd(T x, T y) { return !x or !y? x|y : gcd(y, x % y); }
    inline void reduce() {
        assert(num and den);
        if(num == 0) den = 1;
        else { T g = gcd(abs(num), abs(den)); num /= g; den /= g; if(den < 0) num *= -1, den *= -1; }
    }

    friend const T floor(const frac& r) { return r.num / r.den - ((r.num ^ r.den) < 0 and r.num % r.den); }
    friend const T ceil(const frac& r) { return r.num / r.den + ((r.num ^ r.den) > 0 and r.num % r.den); }
    friend const frac abs(const frac& r) { return r.num < 0? -r : r; }

    int compare(const frac& o) const noexcept {
        if(den == 0 and o.den == 0) return (num ^ o.num) > 0? 0 : num < 0? -1 : 1;
        if(den == 0) return num < 0? -1 : 1;
        if(o.den == 0) return o.num > 0? -1 : 1;
        T up = num * o.den - den * o.num;
        return up == 0? 0 : up < 0? -1 : 1;
    }

    bool operator< (const frac& o) const noexcept { return compare(o) < 0; }
    bool operator> (const frac& o) const noexcept { return compare(o) > 0; }
    bool operator==(const frac& o) const noexcept { return compare(o) == 0; }
    bool operator<=(const frac& o) const noexcept { return compare(o) <= 0; }
    bool operator>=(const frac& o) const noexcept { return compare(o) >= 0; }
    bool operator!=(const frac& o) const noexcept { return compare(o) != 0; }

    const frac operator-() const { return frac(-num, den); }

    frac& operator+=(const frac& o) { 
        num = num * o.den + den * o.num; den *= o.den; reduce(); return *this;
    } const frac operator+(const frac& o) const { return frac(*this) += o; }

    frac& operator-=(const frac& o) { 
        num = num * o.den - den * o.num; den *= o.den; reduce(); return *this;
    } const frac operator-(const frac& o) const { return frac(*this) -= o; }

    frac& operator*=(const frac& o) {
        num *= o.num; den *= o.den; reduce(); return *this;
    } const frac operator*(const frac& o) const { return frac(*this) *= o; }

    frac& operator/=(const frac& o) {
        num *= o.den; den *= o.num; reduce(); return *this;
    } const frac operator/(const frac& o) const { return frac(*this) /= o; }

};

/*
int main() {
    frac<int64_t> p(-4, 9), q;
    cin >> q;
    p += q;
    cout << p;
}
*/
