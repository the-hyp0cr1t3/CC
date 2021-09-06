/**
 🍪 the_hyp0cr1t3
 🍪 06.09.2021 01:57:48
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
    int i, j, n, m;
    cin >> n >> m;
    vector<int64_t> a(n), ans(n), b(n);
    for(auto& x: a) cin >> x;
    vector<vector<int>> g(n), rg(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[--u].pb(--v); rg[v].pb(u);
    }

    int sccount = 0;
    vector<int> comp(n, -1), order;

    auto dfs = Y([&](auto dfs, int v, int k, const auto& gr) -> void {
        comp[v] = k;
        for(auto& x: gr[v])
            if(comp[x] == -1) dfs(x, k, gr);
        if(k == -2) order.pb(v);
    });

    order.reserve(n);
    for(i = 0; i < n; i++)
        if(comp[i] == -1) dfs(i, -2, g);

    reverse(all(order));
    comp.assign(n, -1);
    for(i = j = 0; i < n; i = j) {
        dfs(order[i], sccount++, rg);
        while(j < n and ~comp[order[j]])
            b[comp[order[j]]] += a[order[j]], j++;
    }

    sort(all(order), [&comp](int A, int B) { return comp[A] < comp[B]; });
    for(auto& v: order)
        for(auto& x: g[v])
            if(comp[x] ^ comp[v])
                ans[comp[x]] = max(ans[comp[x]], ans[comp[v]] + b[comp[v]]);

    int64_t res = 0;
    for(i = 0; i < sccount; i++)
        res = max(res, ans[i] + b[i]);

    cout << res;
} // ~W

// ------------------------------------------------------------------------------------

/**
 🍪 the_hyp0cr1t3
 🍪 06.09.2021 01:57:48
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
    int i, j, n, m;
    cin >> n >> m;
    vector<int64_t> a(n), ans(n);
    for(auto& x: a) cin >> x;
    vector<vector<int>> g(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[--u].pb(--v);
    }

    int sccount = 0;
    vector<int> id(n, -1), low(n), onstack(n), comp(n);
    stack<int> st;

    // Tarjan's SCC
    auto dfs = Y([&, cur_id = 0](auto self, int v) mutable -> void {
        id[v] = low[v] = cur_id++;
        onstack[v] = true; st.push(v);
        for(auto& x: g[v]) {
            if(id[x] == -1) self(x), low[v] = min(low[v], low[x]);
            else if(onstack[x]) low[v] = min(low[v], low[x]);
        } if(low[v] == id[v]) {
            while(st.top() != v) {
                comp[st.top()] = sccount;
                onstack[st.top()] = false; st.pop();
            } comp[v] = sccount++; onstack[v] = false; st.pop();
        }
    });

    for(i = 0; i < n; i++)
        if(id[i] == -1) dfs(i);

    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&comp](int A, int B) { return comp[A] > comp[B]; });

    for(i = j = 0; i < n; i = j) {
        int64_t s = 0;
        while(j < n and comp[order[j]] == comp[order[i]])
            s += a[order[j++]];
        ans[comp[order[i]]] += s;
        for(j = i; j < n and comp[order[j]] == comp[order[i]]; j++)
            for(auto& x: g[order[j]])
                if(comp[x] ^ comp[order[j]])
                    ans[comp[x]] = max(ans[comp[x]], ans[comp[order[j]]]);
    }

    cout << *max_element(all(ans));
} // ~W