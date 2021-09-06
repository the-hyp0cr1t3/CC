/**
 🍪 the_hyp0cr1t3
 🍪 17.05.2021 23:01:22
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

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;


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

    int head = -1;
    vector<int> vis(n), ans;
    ans.reserve(n);

    auto dfs = Y([&](auto dfs, int v, int p) -> void {
        vis[v] = true;
        for(auto& x: g[v]) if(x^p and head == -1) {
            if(vis[x] and ans.empty()) head = x;
            if(!vis[x]) dfs(x, v);
        }
        if(~head) {
            ans.pb(v);
            if(v == head)
                head = -1;
        }
    });

    for(i = 0; i < n; i++)
        if(!vis[i]) dfs(i, -1);

    if(ans.empty())
        return cout << "IMPOSSIBLE" << '\n', 0;

    cout << sz(ans)+1 << '\n';
    for(auto& x: ans)
        cout << x+1 << ' ';
    cout << ans.front()+1;
} // ~W