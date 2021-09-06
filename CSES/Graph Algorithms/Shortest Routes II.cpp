/**
 🍪 the_hyp0cr1t3
 🍪 18.05.2021 00:28:26
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

const int64_t k_II = 1e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 500 + 5;
int64_t d[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, k, n, m, Q;
    cin >> n >> m >> Q;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(i ^ j) d[i][j] = k_II;

    for(i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; --u; --v;
        chmin(d[u][v], w); chmin(d[v][u], w);
    }

    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                chmin(d[i][j], d[i][k] + d[k][j]);

    while(Q--) {
        int u, v; cin >> u >> v; --u; --v;
        cout << (d[u][v] == k_II? -1 : d[u][v]) << '\n';
    }
} // ~W