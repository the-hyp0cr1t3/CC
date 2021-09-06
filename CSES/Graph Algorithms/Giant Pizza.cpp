/**
 🍪 the_hyp0cr1t3
 🍪 06.09.2021 01:35:18
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
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n, m;
    cin >> n >> m;

    vector<int> comp(m << 1, -1), order, assignment(m);
    vector<vector<int>> g(m << 1), rg(m << 1);

    auto implies = [&](int p, int q) { g[p].pb(q); rg[q].pb(p); };              // p → q
    auto add_or = [&](int p, int q) { implies(p ^ 1, q); implies(q ^ 1, p); };  // p ∨ q ≡ (¬p → q) ∧ (¬q → p)
    auto add_xor = [&](int p, int q) { add_or(p, q); add_or(p ^ 1, q ^ 1); };   // p ⊕ q ≡ (p ∨ q) ∧ (¬p ∨ ¬q)
    auto add_bicond = [&](int p, int q) { add_xor(p, q ^ 1); };                 // p ↔ q ≡ (p → q) ∧ (q → p) ≡ (p ⊕ ¬q)

    auto dfs = Y([&](auto dfs, int v, int k, const auto& gr) -> void {
        comp[v] = k;
        for(auto& x: gr[v])
            if(comp[x] == -1) dfs(x, k, gr);
        if(k == -2) order.pb(v);
    });


    for(i = 0; i < n; i++) {
        char x, y; int u, v;
        cin >> x >> u >> y >> v;
        add_or(--u << 1 | (x == '-'), --v << 1 | (y == '-'));
    }

    order.reserve(m << 1);
    for(i = 0; i < m << 1; i++)
        if(comp[i] == -1) dfs(i, -2, g);

    reverse(all(order));
    comp.assign(m << 1, -1);

    int _ = 0;
    for(auto& v: order)
        if(comp[v] == -1)
            dfs(v, _++, rg);

    bool bad = false;
    for(i = 0; i < m; i++) {
        if(comp[i << 1] == comp[i << 1 | 1]) bad = true;
        assignment[i] = comp[i << 1] > comp[i << 1 | 1];
    }

    if(bad)
        cout << "IMPOSSIBLE";
    else
        for(auto x: assignment)
            cout << (x? '+' : '-');
} // ~W