/**
 🍪 the_hyp0cr1t3
 🍪 18.05.2021 11:18:52
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

struct edge_t {
    int u{-1}, v{-1}; int64_t w{0};
    edge_t() = default;
    edge_t(int u, int v, int64_t w = 0) : u(u), v(v), w(w) {}
    bool operator<(const edge_t& other) { return w < other.w; }
    friend ostream& operator<<(ostream& os, const edge_t& e) { os << e.u << ' ' << e.v << ' ' << e.w; return os; }
};

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m, x;
    cin >> n >> m;
    vector<edge_t> edges(m);
    for(auto& e: edges) {
        cin >> e.u >> e.v >> e.w;
        --e.u; --e.v;
    }

    bool changed;
    vector<int> p(n, -1);
    vector<int64_t> d(n);
    for(i = 0; i < n; i++) {
        changed = false;
        for(auto& e: edges)
            if(chmin(d[e.v], d[e.u] + e.w))
                changed = true, x = e.v, p[e.v] = e.u;
    }

    if(!changed) return cout << "NO" << '\n', 0;

    for(i = 0; i < n; i++) x = p[x];
    vector<int> ans; ans.reserve(n);
    i = x;
    do { ans.pb(i); i = p[i]; } while(i ^ x);
    ans.pb(i);
    reverse(all(ans));

    cout << "YES" << '\n';
    for(auto& x: ans)
        cout << x+1 << ' ';
} // ~W