/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 18:50:14
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
int dp[N+1];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n;
    cin >> n;
    for(dp[i = 0] = 1; i < n; i++) {
        int x; cin >> x;
        for(j = N-1; j >= x; --j)
            if(dp[j-x]) dp[j] = true;
    }
 
    cout << accumulate(dp+1, dp+N, 0) << '\n';
    for(i = 1; i < N; i++)
        if(dp[i]) cout << i << ' ';
} // ~W 