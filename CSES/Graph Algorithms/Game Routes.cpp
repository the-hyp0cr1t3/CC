/**
 🍪 the_hyp0cr1t3
 🍪 19.05.2021 18:22:59
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
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> indeg(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].pb(v); indeg[v]++;
    }

    queue<int> q;
    vector<int> order; order.reserve(n);
    for(i = 0; i < n; i++)
        if(!indeg[i]) q.push(i);
    while(!q.empty()) {
        auto v = q.front(); q.pop();
        order.pb(v);
        for(auto& x: g[v])
            if(!--indeg[x]) q.push(x);
    }

    vector<int> dp(n); dp[0] = 1;
    for(auto& v: order) {
        for(auto& x: g[v]) {
            dp[x] += dp[v];
            if(dp[x] >= MOD)
                dp[x] -= MOD;
        }
    }

    cout << dp[n-1];
} // ~W