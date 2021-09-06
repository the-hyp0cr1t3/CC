/**
 🍪 the_hyp0cr1t3
 🍪 28.08.2021 00:10:58
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
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for(i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[--u].pb(--v, w);
    }

    struct state {
        int v; int64_t dist;
        state(int v, int64_t dist): v(v), dist(dist) {}
        bool operator<(const state& o) const {
            return dist > o.dist;
        }
    };

    vector<int> ways(n), mn(n), mx(n);
    ways[0] = 1;

    vector<int64_t> d(n, k_II);
    priority_queue<state> pq;
    pq.emplace(0, d[0] = 0);

    while(!pq.empty()) {
        state top = pq.top(); pq.pop();
        if(top.dist > d[top.v]) continue;
        for(auto& [to, w]: g[top.v]) {
            if(d[to] == top.dist + w) {
                ways[to] += ways[top.v];
                if(ways[to] >= MOD) ways[to] -= MOD;
                mn[to] = min(mn[to], mn[top.v] + 1);
                mx[to] = max(mx[to], mx[top.v] + 1);
            } else if(chmin(d[to], top.dist + w)) {
                ways[to] = ways[top.v];
                mn[to] = mn[top.v] + 1; mx[to] = mx[top.v] + 1;
                pq.emplace(to, d[to]);
            }
        }
    }

    cout << d.back() << ' ' << ways.back() << ' ' << mn.back() << ' ' << mx.back();
} // ~W