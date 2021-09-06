/**
 🍪 the_hyp0cr1t3
 🍪 17.05.2021 22:39:20
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
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].pb(v); g[v].pb(u);
    }

    queue<int> q; q.push(0);
    vector<int> d(n, -1), p(n, -1); d[0] = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(auto nxt : g[cur]) {
            if(d[nxt] == -1) {
                d[nxt] = d[cur] + 1;
                p[nxt] = cur;
                q.push(nxt);
            }
        }
    }

    if(d.back() == -1)
        return cout << "IMPOSSIBLE" << '\n', 0;

    i = n-1;
    vector<int> ans; ans.reserve(d.back());
    while(~i) ans.pb(exchange(i, p[i]));
    reverse(all(ans));

    cout << d.back()+1 << '\n';
    for(auto x: ans) cout << x+1 << ' ';
} // ~W