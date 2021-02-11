/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 18:21:37
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
const int N = 2e5 + 5;
int dp[N], cost[N], val[N];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, S;
    cin >> n >> S;
    for(i = 0; i < n; i++)
        cin >> cost[i];
    for(i = 0; i < n; i++)
        cin >> val[i];
 
    for(i = 0; i < n; i++)
        for(j = S; j >= cost[i]; --j)
            chmax(dp[j], dp[j-cost[i]] + val[i]);
 
    cout << *max_element(dp, dp+S+1);
} // ~W 