/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 18:07:34
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
const int N = 1000 + 5;
int dp[N][N];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n;
    cin >> n;
    vector<string> a(n);
    for(auto& x: a) cin >> x;
 
    dp[1][0] = a[0][0] == '.';
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(a[i-1][j-1] == '.') dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
 
    cout << dp[n][n];
} // ~W 