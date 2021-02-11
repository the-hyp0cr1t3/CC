/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 18:37:28
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
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };
 
const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 5000 + 5;
int dp[N][N];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, m; string s, t;
    cin >> s >> t; n = sz(s); m = sz(t);
 
    for(i = 0; i <= n; i++)
        for(j = 0; j <= m; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
 
    for(i = 0; i <= n; i++) {
        for(j = 0; j <= m; j++) {
            if(i) chmin(dp[i][j], dp[i-1][j] + 1);
            if(j) chmin(dp[i][j], dp[i][j-1] + 1);
            if(i and j) chmin(dp[i][j], dp[i-1][j-1] + (s[i-1] != t[j-1]));
        }
    }
    
    cout << dp[n][m];
} // ~W 