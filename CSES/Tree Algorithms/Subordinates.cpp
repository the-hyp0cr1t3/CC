/**
 🍪 thew6rst
 🍪 11.02.2021 19:18:21
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
    for(i = 1; i < n; i++) {
        int p; cin >> p;
        g[--p].pb(i);
    }
    
    vector<int> sub(n, 1);
    Y([&](auto dfs, int v) -> void {
        for(auto& x: g[v]) {
            dfs(x);
            sub[v] += sub[x];
        }
    })(0);
    
    for(auto& x: sub)
        cout << x-1 << ' ';
} // ~W 