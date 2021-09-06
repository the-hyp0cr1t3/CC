/**
 🍪 the_hyp0cr1t3
 🍪 18.05.2021 01:42:23
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
    vector<vector<pair<int, int>>> g(n);
    for(i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[--u].pb(--v, w);
    }

    struct state {
        int v, o; int64_t dist;
        state(int v, int o, int64_t dist): v(v), o(o), dist(dist) {}
        bool operator<(const state& o) const {
            return dist > o.dist;
        }
    };

    array<vector<int64_t>, 2> d;
    d[0] = d[1] = vector<int64_t>(n, k_II);
    priority_queue<state> pq;
    pq.emplace(0, 0, d[0][0] = 0);
    while(!pq.empty()) {
        state top = pq.top(); pq.pop();
        if(top.dist > d[top.o][top.v]) continue;
        for(auto& [to, w]: g[top.v]) {
            if(chmin(d[top.o][to], top.dist + w))
                pq.emplace(to, top.o, d[top.o][to]);
            if(!top.o and chmin(d[1][to], top.dist + w/2))
                pq.emplace(to, 1, d[1][to]);
        }
    }

    cout << min(d[0].back(), d[1].back());
} // ~W