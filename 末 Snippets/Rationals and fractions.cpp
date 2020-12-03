template<class T>
struct frac {
    T num, den;
    static T gcd(T x, T y) { return !x or !y? x|y : gcd(y, x % y); }
    static T abs(T x) { return x < 0? -x : x; }
    frac(T num = 0, T den = 1): num(num), den(den) {}
    explicit operator T() { return floor(); }
    frac& reduce() {
        if(num == 0) {
            den = 1;
        } else {
            T g = gcd(abs(num), abs(den)); num /= g; den /= g;
            if(den < 0) num *= -1, den *= -1;            
        } return *this;
    } friend frac reduce(frac r) { frac o = r; return o.reduce(); }

    T floor() const {
        if(num%den) return num/den - ((num < 0) ^ (den < 0));
        else return num / den;
    } friend T floor(const frac& r) { return r.floor(); }
    T ceil() const { return floor() + !!(num%den); }
    friend T ceil(const frac& r) { return r.ceil(); }

    friend ostream& operator<<(ostream& os, const frac& r) { return os << r.num << " / " << r.den; }
    frac operator-() const { return frac(-num, den); }
    frac operator+(const frac& r) const {
        return frac(num * r.den + den * r.num, den * r.den);
    } frac& operator+=(const frac& r) { return *this = (*this) + r; }
    frac operator-(const frac& r) const {
        return frac(num * r.den - den * r.num, den * r.den);
    } frac& operator-=(const frac& r) { return *this = (*this) - r; }
    frac operator*(const frac& r) const {
        return frac(num * r.num, den * r.den);
    } frac& operator*=(const frac& r) { return *this = (*this) * r; }
    frac operator/(const frac& r) const {
        return frac(num * r.den, den * r.num);
    } frac& operator/=(const frac& r) { return *this = (*this) / r; }

    friend bool operator<(const frac& a, const frac& b) {
        if(!a.den or !b.den) return !b.den;
        T up = a.num * b.den - a.den * b.num;
        if(up == 0) return 0;
        return (up < 0) ^ (a.den < 0) ^ (b.den < 0);
    } friend bool operator>(const frac& a, const frac& b) { return b < a; }
    friend bool operator==(const frac& a, const frac& b) {
        return !(a.num * b.den - a.den * b.num);
    } friend bool operator!=(const frac& a, const frac& b) { return !(a == b); }
    friend bool operator<=(const frac& a, const frac& b) { return !(a > b); }
    friend bool operator>=(const frac& a, const frac& b) { return !(a < b); }
};
