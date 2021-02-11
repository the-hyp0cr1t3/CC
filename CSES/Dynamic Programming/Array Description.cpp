/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 18:26:28
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
const int N = 1e5 + 5;
const int M = 100 + 5;
int64_t dp[N][M], a[N];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, m;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        cin >> a[i];
 
    if(!a[0]) fill(dp[0]+1, dp[0]+m+1, 1);
    else dp[0][a[0]] = 1;
 
    for(i = 1; i < n; i++) {
        if(a[i]) {
            dp[i][a[i]] = dp[i-1][a[i]-1] + dp[i-1][a[i]] + dp[i-1][a[i]+1];
            dp[i][a[i]] %= MOD;
        } else {
            for(j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
    } cout << accumulate(dp[n-1], dp[n-1]+m+1, 0ll) % MOD;
} // ~W 