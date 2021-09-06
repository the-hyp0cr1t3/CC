/**
 🍪 the_hyp0cr1t3
 🍪 06.09.2021 20:31:44
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, j, n, m;
    cin >> n >> m;
    vector adj(n, vector<int>(n));
    while(m--) {
        int u, v; cin >> u >> v;
        adj[--u][--v]++;
    }

    vector dp(1 << n, vector<int64_t>(n));
    dp[1][0] = 1;

    for(int mask = 1; mask < 1 << n; mask++) {
        for(i = 0; i < n; i++) if(mask >> i & 1 and dp[mask][i]) {
            for(j = 1; j < n; j++) if(~mask >> j & 1 and adj[i][j]) {
                dp[mask | 1 << j][j] += dp[mask][i] * adj[i][j];
                dp[mask | 1 << j][j] %= MOD;
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1];
} // ~W