/**
 🍪 thew6rst
 🍪 11.02.2021 20:15:33
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
    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].pb(v); g[v].pb(u);
    }
    
    auto bfs = [&] (int root) {
        queue<int> q; q.push(root);
        vector<int> d(n, -1); d[root] = 0;
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            for(auto nxt : g[cur]) {
                if(d[nxt] == -1) {
                    d[nxt] = d[cur] + 1;
                    q.push(nxt);
                }
            }
        } auto it = max_element(all(d));
        return make_pair(it-d.begin(), *it);
    };

    cout << bfs(bfs(0).first).second;
} // ~W 