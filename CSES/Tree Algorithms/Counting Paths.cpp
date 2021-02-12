/**
 🍪 thew6rst
 🍪 12.02.2021 10:45:31
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
const int LG = 20;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].pb(v); g[v].pb(u);
    }
    
    array<vector<int>, LG> anc;
    for(auto& x: anc) x.assign(n, -1);

    vector<int> depth(n);
    Y([&](auto dfs, int v, int p) -> void {
        anc[0][v] = p;
        for(int k = 1; k < LG; k++)
            anc[k][v] = ~anc[k-1][v]? anc[k-1][anc[k-1][v]] : -1;
        for(auto& x: g[v]) if(x ^ p)
            depth[x] = depth[v] + 1, dfs(x, v);
    })(0, -1);

    auto LCA = [&depth, &anc](int u, int v) {
        if(depth[u] < depth[v])
            swap(u, v);
        for(int k = LG-1; ~k; k--)
            if(depth[u]-depth[v] >> k & 1)
                u = anc[k][u];
        if(u == v)
            return u;
        for(int k = LG-1; ~k; k--)
            if(anc[k][u] ^ anc[k][v])
                u = anc[k][u], v = anc[k][v];
        return anc[0][u];
    };

    vector<int> pref(n);
    while(m--) {
        int u, v; cin >> u >> v;
        int lca = LCA(--u, --v);
        pref[u]++; pref[v]++;
        pref[lca]--;
        if(lca) pref[anc[0][lca]]--;
    }

    Y([&](auto dfs, int v, int p) -> void {
        for(auto& x: g[v]) if(x^p) {
            dfs(x, v); pref[v] += pref[x];
        }
    })(0, -1);
    
    for(auto& x: pref) cout << x << ' ';
} // ~W 