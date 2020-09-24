struct Two_SAT {
    int n, m, sccount{0}; bool ok{true};
    vector<vector<int>> g, rg;
    vector<int> comp, assignment;
    vector<bool> vis; stack<int> st;

    Two_SAT(int n): n(2*n) {
        vis.resize(n); comp.resize(n);
        g.resize(n); rg.resize(n);
    }

    void addedge(int u, int v) {
        g[u].pb(v);
        rg[v].pb(u);        
    }

    void dfs1(int v) {
        vis[v] = 1;
        for(auto x: g[v]) 
            if(!vis[x]) dfs1(x);
        st.push(v);
    }

    void dfs2(int v, int k) {
        comp[v] = k;
        for(auto& x: rg[v]) 
            if(!comp[x]) dfs2(x, k);
    }

    // Kosaraju's SCC
    void scc() {
        for(int i = 0; i < n; i++) 
            if(!vis[i]) dfs1(i);
        while(!st.empty()) {
            sccount++;
            dfs2(st.top(), sccount);
            while(!st.empty() and comp[st.top()]) st.pop();
        }
    }

    bool is_sat() {
        scc();
        assignment.resize(n);
        for(int i = 0; i < n; i++) {
            if(comp[i] == comp[i^1]) ok = 0;
            assignment[i] = !(comp[i] > comp[i^1]);
        }
        return ok;
    }
};
