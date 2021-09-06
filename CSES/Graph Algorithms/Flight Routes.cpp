/**
 🍪 the_hyp0cr1t3
 🍪 06.09.2021 00:24:44
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
    int i, n, m, k;
    cin >> n >> m >> k;
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

    vector d(n, vector<int64_t>(k, k_II));
    priority_queue<state> pq;
    pq.emplace(0, d[0][0] = 0);
    while(!pq.empty()) {
        state top = pq.top(); pq.pop();
        if(top.dist > d[top.v][k - 1]) continue;
        for(auto& [to, w]: g[top.v])
            if(chmin(d[to][k - 1], top.dist + w))
                pq.emplace(to, top.dist + w), sort(all(d[to]));
    }

    for(auto& x: d[n - 1])
        cout << x << ' ';
} // ~W