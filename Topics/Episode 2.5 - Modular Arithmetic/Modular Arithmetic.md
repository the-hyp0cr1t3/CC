# Modular arithmetic
This is a small but important topic. Following are links to some theory on it.

[Tutorial](https://codeforces.com/blog/entry/72527)

[Errichto video](https://www.youtube.com/watch?v=-OPohCQqi_E)

[Modular Inverse](https://cp-algorithms.com/algebra/module-inverse.html)

[Try this problem](https://open.kattis.com/problems/modulararithmetic)

<details>
  <summary>My solution in C++</summary>
```c++
// https://open.kattis.com/problems/modulararithmetic
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
 
// Modular inverse exists iff a, MOD are coprime
 
// Using binary exponentiation
    // inv(a) = a^(MOD-2)
    // works only when MOD is prime
    // see Fermat's little theorem
ll expo(ll A, ll B, ll MOD) {      // A^B % MOD
    ll res = 1;
    A %= MOD;
    while(B > 0) {
        if(B & 1) res = res * A % MOD;
        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}
 
// Using Extended Euclidean algorithm
    // inv(a, MOD) = -(MOD/a) * inv(MOD, a) % MOD
    // Proof := https://cp-algorithms.com/algebra/module-inverse.html#toc-tgt-4
    // works when a and MOD are coprime
ll inv(ll a, ll m) {        // inv(a, MOD)
    a %= m; 
    if(a == 1) return 1;
    return m - inv(m, a) * m / a;
} 
 
int solve(ll MOD) {
    ll a, b, ans; char c;
    cin >> a >> c >> b;
    a %= MOD;
    b %= MOD;
    if(c == '+') ans = a+b;
    if(c == '-') ans = a-b+MOD;
    if(c == '*') ans = a*b;
    if(c == '/') {
        if(__gcd(b, MOD) > 1) return cout << -1 << endl, 0;
        ans = a * inv(b, MOD);
    }
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
 
int32_t main() {
    IOS;
    int Q; ll MOD;
    while(cin >> MOD >> Q, MOD)
        while(Q--) solve(MOD);
    return 0;
}
```
</details>
