/**
 🍪 thew6rst
 🍪 12.02.2021 12:18:30
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
    int i, n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for(auto& x: a) cin >> x;

    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].pb(v); g[v].pb(u);
    }
    
    vector<int> order, sub(n, 1), tin(n);
    order.reserve(n);
    Y([&](auto dfs, int v, int p) -> void {
        tin[v] = sz(order); order.pb(v);
        for(auto& x: g[v]) if(x^p) {
            dfs(x, v); sub[v] += sub[x];
        }
    })(0, -1);
    
    vector<int64_t> seg(n<<1);
    for(i = 0; i < n; i++)
        seg[i+n] = a[order[i]];
    for(i = n-1; i; i--)
        seg[i] = seg[i<<1] + seg[i<<1|1];

    auto query = [&seg, n](int l, int r) {
        int64_t res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) res += seg[l++];
            if(r&1) res += seg[--r];
        } return res;
    };

    auto update = [&seg, n](int pos, int val) {
        for(seg[pos += n] = val; pos >>= 1; )
            seg[pos] = seg[pos<<1] + seg[pos<<1|1];
    };

    while(Q--) {
        int o, v; cin >> o >> v; v--;
        if(o == 1) {
            int x; cin >> x;
            update(tin[v], x);
        } else {
            cout << query(tin[v], tin[v]+sub[v]) << '\n';
        }
    }
} // ~W 