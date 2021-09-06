/**
 🍪 the_hyp0cr1t3
 🍪 06.03.2021 19:01:10
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

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

struct edge_t {
    int u{-1}, v{-1}; int64_t w{0}; bool done{false};
    edge_t() = default;
    edge_t(int u, int v, int64_t w = 0) : u(u), v(v), w(w) {}
    bool operator<(const edge_t& other) { return w < other.w; }
    friend ostream& operator<<(ostream& os, const edge_t& e) { os << e.u << ' ' << e.v << ' ' << e.w; return os; }
};

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m;
    cin >> n >> m;

    vector<int> deg(n);
    vector<edge_t> edges;
    edges.reserve(m);
    vector<vector<edge_t*>> g(n);

    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        deg[--u]++; deg[--v]++;
        edges.pb(u, v);
        g[u].pb(&edges.back());
        g[v].pb(&edges.back());
    }

    bool bad = false;
    for(i = 0; i < n; i++)
        bad |= deg[i] & 1;

    if(bad)
        return cout << "IMPOSSIBLE" << '\n', 0;

    vector<int> tour;
    tour.reserve(m+1);
    Y([&](auto dfs, int v) -> void {
        while(deg[v]-- > 0) {
            auto e = g[v][deg[v]];
            if(!e->done)
                e->done = true, dfs(e->u ^ e->v ^ v);
        } tour.pb(v);
    })(0);

    for(i = 0; i < n; i++)
        if(deg[i] > 0)
            return cout << "IMPOSSIBLE" << '\n', 0;

    reverse(all(tour));
    for(auto& x: tour) cout << ++x << ' ';
} // ~W