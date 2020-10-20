vector<pair<int, int>> g[N];
for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].pb(v, w);
    g[v].pb(u, w);
}

auto dijkstra = [&] (int root) {
    vector<int64_t> d(n, INF);
    vector<int> par(n, -1);
    struct state {
        int v; int64_t dist;
        state(int v, int64_t dist): v(v), dist(dist) {}
        bool operator<(const state& o) { return dist > o.dist; }
    }; priority_queue<state> pq;
    for(d[root] = i = 0; i < n; i++)
        pq.emplace(i, d[i]);
    while(!pq.empty()) {
        state top = pq.top(); pq.pop();
        if(top.dist > d[top.v]) continue;
        for(auto& [to, w]: g[v])
            if(chmin(d[to], curd + w))
                pq.emplace(to, d[to]), par[to] = v;
    }
};
