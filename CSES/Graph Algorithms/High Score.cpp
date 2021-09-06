/**
 🍪 the_hyp0cr1t3
 🍪 18.05.2021 00:58:18
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

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

struct edge_t {
    int u{-1}, v{-1}; int64_t w{0};
    edge_t() = default;
    edge_t(int u, int v, int64_t w = 0) : u(u), v(v), w(w) {}
    bool operator<(const edge_t& other) { return w < other.w; }
    friend ostream& operator<<(ostream& os, const edge_t& e) { os << e.u << ' ' << e.v << ' ' << e.w; return os; }
};

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m;
    cin >> n >> m;
    vector<edge_t> edges(m);
    for(auto& e: edges) {
        cin >> e.u >> e.v >> e.w;
        e.u--; e.v--; e.w *= -1;
    }

    vector<int> cycle(n);
    vector<int64_t> d(n, k_II); d[0] = 0;
    for(i = 0; i < n; i++) {
        for(auto& e: edges) {
            if(!chmin(d[e.v], d[e.u] + e.w))
                continue;
            if(i+1 == n)
                cycle[e.v] = true;
        }
    }

    auto dfs = Y([&](auto dfs, int v, auto& g, auto& vis) -> void {
        vis[v] = true;
        for(auto& x: g[v])
            if(!vis[x]) dfs(x, g, vis);
    });

    vector<int> vis(n), rvis(n);
    vector<vector<int>> g(n), rg(n);
    for(auto& e: edges) {
        g[e.u].pb(e.v);
        rg[e.v].pb(e.u);
    }

    dfs(0, g, vis);
    dfs(n-1, rg, rvis);

    bool neg = false;
    for(i = 0; i < n; i++)
        neg |= cycle[i] and vis[i] and rvis[i];

    cout << (neg? -1 : -d.back());
} // ~W