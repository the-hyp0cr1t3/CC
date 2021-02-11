/**
 🍪 thew6rst
 🍪 11.02.2021 17:06:56
**/
#ifdef W
    #include "k_II.h"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 101;
const int M = 1e6 + 5;
int dp[N][M];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& x: a) cin >> x;

    dp[0][0] = 1;
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            int remain = j - a[i-1];
            if(remain >= 0) {
                dp[i][j] += dp[i][remain];
                if(dp[i][j] >= MOD)
                    dp[i][j] -= MOD;
            }
        }
    }

    cout << dp[n][k];
} // ~W 