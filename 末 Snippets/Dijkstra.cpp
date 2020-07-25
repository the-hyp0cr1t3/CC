int d[N], p[N];
vector<pii> g[N];
for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].pb(v, w);
    g[v].pb(u, w);
}

auto dijkstra = [&] (int root) {
    set<pii> q;
    q.ins({0, root});
    
    memset(p, -1, sizeof(p));
    for(i = 0; i < n; i++) 
        d[i] = INF;
    d[root] = 0;

    while(!q.empty()) {
        auto [y, v] = *q.begin();
        q.erase(q.begin());
        for(auto& [to, w]: g[v]) {
            if(d[to] > d[v] + w) {
                q.erase({d[to], to});
                d[to] = d[v] + w;
                q.ins({d[to], to});
                p[to] = v;
            }
        }
    }    
};

