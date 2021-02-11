/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 18:44:16
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
const int N = 500 + 5;
int dp[N][N];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, k, a, b;
    cin >> a >> b;
    
    for(i = 1; i <= a; i++) {
        for(j = 1; j <= b; j++) {
            if(i == j) continue;
            dp[i][j] = INF;
            for(k = 1; k < i; k++)
                chmin(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            for(k = 1; k < j; k++)
                chmin(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
        }
    } cout << dp[a][b];
} // ~W 