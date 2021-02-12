/**
 🍪 thew6rst
 🍪 11.02.2021 20:24:44
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
    
    vector<array<array<int, 2>, 2>> dp(n);
    Y([&](auto dfs, int v, int p) -> void {
        dp[v][0] = dp[v][1] = {0, -1};
        for(auto& x: g[v]) if(x^p) {
            dfs(x, v);
            array<int, 2> cand = {dp[x][0][0] + 1, x};
            if(cand[0])
                dp[v][1] = cand > dp[v][0]? exchange(dp[v][0], cand) : max(dp[v][1], cand);
        }
    })(0, -1);
    
    Y([&](auto dfs, int v, int p) -> void {
        for(auto& x: g[v]) if(x^p) {
            array<int, 2> cand = {dp[v][!(dp[v][0][1] ^ x)][0] + 1, v};
            dp[x][1] = cand > dp[x][0]? exchange(dp[x][0], cand) : max(dp[x][1], cand);
            dfs(x, v);
        }
    })(0, -1);
    
    for(i = 0; i < n; i++)
        cout << dp[i][0][0] << " \n"[i == n-1];
} // ~W 