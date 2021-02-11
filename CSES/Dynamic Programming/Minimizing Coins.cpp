/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 17:31:52
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
const int N = 1e6 + 5;
int c[N], dp[N];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, S;
    cin >> n >> S;
    for(i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c+n);
 
    for(i = 0; i <= S; i++)
        dp[i] = INF;
    dp[0] = 0;
 
    for(i = 0; i <= S; i++)
        for(j = 0; j < n; j++)
            if(i + c[j] <= S)
                chmin(dp[i+c[j]], dp[i] + 1);
    
    cout << (dp[S] == INF? -1 : dp[S]);
} // ~W 