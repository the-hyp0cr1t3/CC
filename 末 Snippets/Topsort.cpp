int indeg[N];
vector<int> g[N];

for(i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    indeg[v]++;
}

auto topsort = [&]() {
    queue<int> q;
    vector<int> order; order.reserve(n);
    for(i = 0; i < n; i++) 
        if(!indeg[i]) q.push(i);
    while(!q.empty()) {
        auto v = q.front();
        q.pop();
        order.pb(v);
        for(auto& x: g[v]) 
            if(!--indeg[x]) q.push(x);
    }
    return sz(order) == n;      // cycle? false : true
};
