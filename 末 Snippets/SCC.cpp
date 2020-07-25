int n, m, sccount = 0;
vector<int> g[N], rg[N], comp;
vector<bool> vis;
stack<int> st;

void makeG() {
    for(int i = 0; i < m; i++) {
        int u, v;
        re(u, v);
        u--, v--;
        g[u].pb(v);
        rg[v].pb(u);
    }
    vis.resize(n);
    comp.resize(n);
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
    for(i = 0; i < n; i++) 
        if(!vis[i]) dfs1(i);

    while(!st.empty()) {
        sccount++;
        dfs2(st.top(), sccount);
        while(!st.empty() and comp[st.top()]) st.pop();
    }
}

/* -------------------------------------------------- */

int n, m, id = 0, sccount = 0;
vector<int> g[N], ids, low;
vector<bool> onstack;
stack<int> st;

void makeG() {
    for(int i = 0; i < m; i++) {
        int u, v;
        re(u, v);
        u--; v--;
        g[u].pb(v);
    }
    ids.assign(n, -1);
    low.rsz(n);
    onstack.rsz(n);
}

// Tarjan's SCC
void dfs(int v) {
    ids[v] = low[v] = id++;
    onstack[v] = 1;
    st.push(v);
    for(auto& x: g[v]) {
        if(ids[x] == -1) 
            dfs(x);
        if(onstack[x]) 
            low[v] = min(low[v], low[x]);
    }
    if(low[v] == ids[v]) {
        while(!st.empty() and st.top() != v) {
            int x = st.top();
            onstack[x] = 0;
            st.pop();
        }
        onstack[v] = 0;
        st.pop();
        sccount++;
    }
};

