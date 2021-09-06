/**
 🍪 the_hyp0cr1t3
 🍪 06.09.2021 00:55:27
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

struct edge_t {
    int u{-1}, v{-1}; int64_t w{0};
    edge_t() = default;
    edge_t(int u, int v, int64_t w = 0) : u(u), v(v), w(w) {}
    bool operator<(const edge_t& other) { return w < other.w; }
};

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, cnt = 0;
    cin >> n >> m;

    vector<edge_t> edges(m);
    for(auto& e: edges)
        cin >> e.u >> e.v >> e.w;
    sort(all(edges));

    vector<int> par(n + 1, -1);
    auto get_par = [&par](int A) {
        while(par[A] >= 0) {
            if(par[par[A]] >= 0)
                par[A] = par[par[A]];
            A = par[A];
        } return A;
    };

    auto merge = [&get_par, &par](int A, int B) {
        A = get_par(A); B = get_par(B);
        if(A == B) return false;
        if(-par[A] < -par[B]) swap(A, B);
        par[A] += par[B]; par[B] = A;
        return true;
    };

    int64_t ans = 0;
    for(auto& e: edges)
        if(merge(e.u, e.v))
            ans += e.w, cnt++;

    if(cnt < n - 1)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << ans << '\n';
} // ~W