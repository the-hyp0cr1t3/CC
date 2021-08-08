# Modular arithmetic
Have you ever seen something like *find the answer modulo 10<sup>9</sup>+7*?  If you're still wondering what it means (or even if you're not), you should read up on *Modular arithmetic*.

**Reading material:**
* [CF Blog [B]](https://codeforces.com/blog/entry/72527)
* [Errichto video [V]](https://www.youtube.com/watch?v=-OPohCQqi_E)
* [SecondThread video [V]](https://www.youtube.com/watch?v=KfTcd0dg0DI)
* *Modular Inverse* - [CP Algorithms](https://cp-algorithms.com/algebra/module-inverse.html)
* *CPH Ch 21,* pg [201](https://cses.fi/book/book.pdf#page=211) - [203](https://cses.fi/book/book.pdf#page=213)

Try [this](https://open.kattis.com/problems/modulararithmetic) problem.

<details>
  <summary>My solution in C++</summary>
  
```c++
/**
 🍪 the_hyp0cr1t3
 🍪 09.08.2021 00:32:48
**/
#include <bits/stdc++.h>
using namespace std;

// Using binary exponentiation
  // inv(a) = a^(MOD-2)
  // works only when MOD is prime
  // see Fermat's little theorem
int64_t expo(int64_t a, int64_t b, int64_t MOD) {      // a^b % MOD
    int64_t res = 1;
    a %= MOD;
    while(b > 0) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}


// Using Extended Euclidean algorithm
  // inv(a, MOD) = -(MOD/a) * inv(MOD, a) % MOD
  // Proof := https://cp-algorithms.com/algebra/module-inverse.html#toc-tgt-4
  // works when a and MOD are coprime
int64_t inv(int64_t a, int64_t m) {        // inv(a, MOD)
    a %= m;
    if(a == 1) return 1;
    return m - inv(m, a) * m / a;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int Q; int64_t MOD;
    while(cin >> MOD >> Q, MOD) {
        while(Q--) {
            int64_t a, b, ans; char op;
            cin >> a >> op >> b;
            a %= MOD;
            b %= MOD;

            bool bad = op == '/' and gcd((int64_t)b, MOD) != 1;

            if(op == '+')
                ans = (a + b) % MOD;
            else if(op == '-')
                ans = ((a - b) % MOD + MOD) % MOD;
            else if(op == '*')
                ans = a * b % MOD;
            else if(!bad)
                ans = a * inv(b, MOD) % MOD;

            if(bad) cout << -1 << '\n';
            else cout << ans << '\n';
        }
    }

} // ~W
```
</details>

<details>
  <summary>Modint template solution in C++</summary>
  
```c++
/**
 🍪 the_hyp0cr1t3
 🍪 09.08.2021 00:32:48
**/
#include <bits/stdc++.h>
using namespace std;

template<const int64_t& MOD>
struct Mint {
    using T = typename decay<decltype(MOD)>::type; T v;
    Mint(int64_t v = 0) { if(v < 0) v = v % MOD + MOD; if(v >= MOD) v %= MOD; this->v = T(v); }
    Mint(uint64_t v) { if (v >= MOD) v %= MOD; this->v = T(v); }
    Mint(int v): Mint(int64_t(v)) {}
    Mint(unsigned v): Mint(uint64_t(v)) {}
    explicit operator int() const { return v; }
    explicit operator int64_t() const { return v; }
    explicit operator uint64_t() const { return v; }
    friend istream& operator>>(istream& in, Mint& m) { int64_t v_; in >> v_; m = Mint(v_); return in; }
    friend ostream& operator<<(ostream& os, const Mint& m) { return os << m.v; }

    static T inv(T a, T m) {
        T g = m, x = 0, y = 1;
        while(a != 0) {
            T q = g / a;
            g %= a; swap(g, a);
            x -= q * y; swap(x, y);
        } return x < 0? x + m : x;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif // x must be less than 2^32 * m
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x), quot, rem;
        asm("divl %4\n" : "=a" (quot), "=d" (rem) : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    Mint inv() const { return Mint(inv(v, MOD)); }
    Mint operator-() const { return Mint(v? MOD-v : 0); }
    Mint& operator++() { v++; if(v == MOD) v = 0; return *this; }
    Mint& operator--() { if(v == 0) v = MOD; v--; return *this; }
    Mint operator++(int) { Mint a = *this; ++*this; return a; }
    Mint operator--(int) { Mint a = *this; --*this; return a; }
    Mint& operator+=(const Mint& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(const Mint& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(const Mint& o) { v = fast_mod(uint64_t(v) * o.v); return *this; }
    Mint& operator/=(const Mint& o) { return *this *= o.inv(); }
    friend Mint operator+(const Mint& a, const Mint& b) { return Mint(a) += b; }
    friend Mint operator-(const Mint& a, const Mint& b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint& a, const Mint& b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint& a, const Mint& b) { return Mint(a) /= b; }
    friend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }
    friend bool operator!=(const Mint& a, const Mint& b) { return a.v != b.v; }
    friend bool operator<(const Mint& a, const Mint& b) { return a.v < b.v; }
    friend bool operator>(const Mint& a, const Mint& b) { return a.v > b.v; }
    friend bool operator<=(const Mint& a, const Mint& b) { return a.v <= b.v; }
    friend bool operator>=(const Mint& a, const Mint& b) { return a.v >= b.v; }
    Mint operator^(int64_t p) {
        if(p < 0) return inv() ^ -p;
        Mint a = *this, res{1}; while(p > 0) {
            if(p & 1) res *= a;
            p >>= 1; if(p > 0) a *= a;
        } return res;
    }
};

int64_t MOD;
using mint = Mint<MOD>;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int Q;
    while(cin >> MOD >> Q, MOD) {
        while(Q--) {
            char op; mint a, b, ans;
            cin >> a >> op >> b;

            bool bad = op == '/' and gcd((int64_t)b, MOD) != 1;

            if(op == '+')
                ans = a + b;
            else if(op == '-')
                ans = a - b;
            else if(op == '*')
                ans = a * b;
            else if(!bad)
                ans = a / b;

            if(bad) cout << -1 << '\n';
            else cout << ans << '\n';
        }
    }

} // ~W
```
</details>
  
See [snippet](../../末%20Snippets/ModInt.cpp) for implementation.
