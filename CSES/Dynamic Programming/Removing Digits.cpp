/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 18:05:04
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
int dp[N];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n;
    cin >> n;
    
    fill(dp, dp+n, INF);
    for(i = n; i; --i) {
        int x = i;
        while(x) chmin(dp[i-x%10], dp[i] + 1), x /= 10;
    } cout << dp[0];
} // ~W 