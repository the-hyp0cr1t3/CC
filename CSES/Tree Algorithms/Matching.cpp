/**
 🍪 thew6rst
 🍪 11.02.2021 19:39:48
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
    
    vector<array<int, 2>> dp(n);
    Y([&](auto dfs, int v, int p) -> void {
        dp[v] = {};
        for(auto& x: g[v]) if(x^p) {
            dfs(x, v);
            dp[v][0] += dp[x][1];
            chmax(dp[v][1], -dp[x][1] + dp[x][0] + 1);
        } dp[v][1] += dp[v][0];
    })(0, -1);
    
    cout << max(dp[0][0], dp[0][1]);
} // ~W 