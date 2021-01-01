/* Dijkstra's shortest paths */
// (https://cp-algorithms.com/graph/dijkstra.html)

vector<pair<int, int>> g[N];
for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].pb(v, w);
    g[v].pb(u, w);
}

vector<int64_t> d(n, INF);
vector<int> par(n, -1);

auto dijkstra = [&] (int root) {
    struct state {
        int v; int64_t dist;
        state(int v, int64_t dist): v(v), dist(dist) {}
        bool operator<(const state& o) const { 
            return dist > o.dist; 
        }
    }; 
    
    priority_queue<state> pq;
    pq.emplace(root, d[root] = 0);
    
    while(!pq.empty()) {
        state top = pq.top(); pq.pop();
        if(top.dist > d[top.v]) continue;
        for(auto& [to, w]: g[top.v])
            if(d[to] < top.dist + w) {
                d[to] = top.dist + w;
                pq.emplace(to, d[to]);
                par[to] = top.v;
            }
    }
};
