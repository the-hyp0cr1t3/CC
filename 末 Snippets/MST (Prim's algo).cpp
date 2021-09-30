/* Minimum Spanning Tree - Prim's Algorithm */

/*
    https://github.com/the-hyp0cr1t3/CC/blob/master/Beginner%20Topics/%5BS5%5D%20Do%20you%20understand%20the%20graphity%20of%20this%20situation/%5BEP%203%5D%20Spanning%20Trees/%5BPt%203%5D%20Prim%27s%20MST.md
*/

int n, m, inedgewt[N], parent[N];
vector<pii> g[N], tree[N];
vector<bool> vis;

for(i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
}

vis.resize(n);
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
            tree[cur].emplace_back(parent[cur], wt);
            tree[parent[cur]].emplace_back(cur, wt);
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