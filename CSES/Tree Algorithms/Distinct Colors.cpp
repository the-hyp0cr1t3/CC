/**
 🍪 thew6rst
 🍪 12.02.2021 11:45:27
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n;
    cin >> n;
    vector<int> col(n);
    for(auto& x: col) cin >> x;

    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].pb(v); g[v].pb(u);
    }
    
    vector<int> ans(n);
    vector<set<int>> sub(n);
    Y([&](auto dfs, int v, int p) -> void {
        sub[v].insert(col[v]);
        for(auto& x: g[v]) if(x^p) {
            dfs(x, v);
            if(sz(sub[x]) > sz(sub[v]))
                swap(sub[x], sub[v]);
            sub[v].merge(sub[x]);
        } ans[v] = sz(sub[v]);
    })(0, -1);
    
    for(auto& x: ans) cout << x << ' ';
} // ~W 