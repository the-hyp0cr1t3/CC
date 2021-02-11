/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 17:26:32
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
const int N = 1e6 + 10;
int dp[N][6];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, k, n;
    cin >> n;
    
    dp[0][0] = 1;
    for(i = 0; i < n; i++)
        for(j = 0; j < 6; j++)
            for(k = 0; k < 6; k++)
                (dp[i+k+1][k] += dp[i][j]) %= MOD;
 
    int ans = 0;
    for(j = 0; j < 6; j++)
        (ans += dp[n][j]) %= MOD;
    cout << ans;
} // ~W 