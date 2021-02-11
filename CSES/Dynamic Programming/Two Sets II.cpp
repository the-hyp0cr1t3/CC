/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 19:40:29
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
 
const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
int dp[N];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n;
    cin >> n;
    int sum = n * (n+1) >> 1;
 
    if(sum & 1) return cout << 0, 0;
    sum >>= 1;
 
    dp[0] = 1;
    for(i = 1; i <= n; i++)
        for(j = sum; j >= i; --j)
            (dp[j] += dp[j-i]) %= MOD;
 
    cout << (500000004ll * dp[sum] % MOD);
} // ~W 