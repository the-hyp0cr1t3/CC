// Prim's MST
int n, m, inedgewt[N], parent[N];
vector<pii> g[N], tree[N];
vector<bool> vis;

for(i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].pb(v, w);
    g[v].pb(u, w);
}
vis.rsz(n);
for(i = 0; i < n; i++) 
    inedgewt[i] = INF;

auto cmp = [] (const pii A, const pii B) {
    if(A.ff == B.ff) return A.ss < B.ss;
    return A.ff < B.ff;                         // comparing
};

auto primsMST = [&] (int root) {
    set<pii, decltype(cmp)> s(cmp);
    s.ins({0, root});
    
    int cost = 0;
    inedgewt[root] = 0;
    parent[root] = -1;
    
    while(!s.empty()) {
        auto [wt, cur] = *s.begin();
        s.erase(s.begin());
        
        vis[cur] = 1;
        cost += wt;
        if(~parent[cur]) {
            tree[cur].pb(parent[cur], wt);
            tree[parent[cur]].pb(cur, wt);
        }
        
        for(auto [to, newwt] : g[cur]) {
            if(vis[to])
                continue;
            if(inedgewt[to] > newwt) {               // comparing
                s.erase({inedgewt[to], to});
                inedgewt[to] = newwt;
                s.ins({inedgewt[to], to});
                parent[to] = cur;
            }
        }
    }
    return cost;
};

/* -------------------------------------------------- */
// Krukal's MST
struct edge_t {
    int u, v, w;
    edge_t(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const edge_t& other) { return w < other.w; }
    friend ostream& operator<<(ostream& os, edge_t& e) { os << e.u << ' ' << e.v << ' ' << e.w; return os; }
};

vector<int> par(n), sz_(n, 1);
iota(all(par), 0);

auto getpar = [&] (int x) {
    int pp = x;
    while(par[pp] != pp)
        pp = par[pp];
    while(par[x] != x) {
        int z = par[x];
        par[x] = pp;
        x = z;
    }
    return pp;        
};

auto merge = [&] (int x, int y) {
    x = getpar(x);
    y = getpar(y);
    if (x == y) return false;
    if (sz_[x] < sz_[y]) swap(x, y);
    par[y] = x, sz_[x] += sz_[y];
    return true;
};

vector<edge_t> edges, ans;
// ...
sort(all(edges));
int cost = 0;

for(auto& e: edges)
    if(merge(e.u, e.v))
        cost += e.w, ans.pb(e);

