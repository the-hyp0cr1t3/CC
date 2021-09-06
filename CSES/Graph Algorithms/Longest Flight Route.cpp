/**
 🍪 the_hyp0cr1t3
 🍪 06.09.2021 00:33:57
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
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n, m;
    cin >> n >> m;
    vector<int> indeg(n);
    vector<vector<int>> g(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[--u].pb(--v); indeg[v]++;
    }

    vector<int> par(n, -1), dp(n, -INF);
    dp[0] = 1;

    queue<int> q;
    for(i = 0; i < n; i++)
        if(!indeg[i]) q.push(i);

    while(!q.empty()) {
        auto v = q.front(); q.pop();
        for(auto& x: g[v]) {
            if(!--indeg[x]) q.push(x);
            if(chmax(dp[x], dp[v] + 1)) par[x] = v;
        }
    }

    if(dp[n - 1] < 0)
        return cout << "IMPOSSIBLE" << '\n', 0;

    vector<int> ans;
    ans.reserve(dp[n - 1]);
    for(i = n-1; ~i; i = par[i]) ans.pb(i);
    reverse(all(ans));

    cout << sz(ans) << '\n';
    for(auto& x: ans) cout << x + 1 << ' ';
} // ~W