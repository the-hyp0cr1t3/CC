/* Strongly Connected Components */
// (https://www.youtube.com/watch?v=z9oOadBgO9I&ab_channel=AlgorithmsLive)

// Kosaraju's algorithm (https://cp-algorithms.com/graph/strongly-connected-components.html)
int sccount = 0;
vector<vector<int>> g(n), rg(n);
vector<int> comp(n);
vector<bool> vis(n);
stack<int> st;

for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v; u--, v--;
    g[u].push_back(v); rg[v].push_back(u);
}

function<void(int)> dfs1 = [&](int v) {
    vis[v] = 1;
    for(auto x: g[v]) 
        if(!vis[x]) dfs1(x);
    st.push(v);
};

function<void(int, int)> dfs2 = [&](int v, int k) {
    comp[v] = k;
    for(auto& x: rg[v]) 
        if(!comp[x]) dfs2(x, k);
};

for(i = 0; i < n; i++) 
    if(!vis[i]) dfs1(i);

while(!st.empty()) {
    sccount++;
    dfs2(st.top(), sccount);
    while(!st.empty() and comp[st.top()]) st.pop();
}

/* -------------------------------------------------- */
// Tarjan's algorithm
vector<int> g[N];

int id = 0, sccount = 0;
vector<int> ids(n, -1), low(n);
vector<bool> onstack(n);
stack<int> st;

// Tarjan's SCC
function<void(int)> dfs = [&](int v) {
    ids[v] = low[v] = id++;
    onstack[v] = 1; st.push(v);
    for(auto& x: g[v]) {
        if(ids[x] == -1) dfs(x);
        if(onstack[x]) low[v] = min(low[v], low[x]);
    }
    if(low[v] == ids[v]) {
        while(!st.empty() and st.top() != v) {
            onstack[st.top()] = 0; st.pop();
        } onstack[v] = 0; st.pop(); sccount++;
    }
};

for(i = 0; i < n; i++) if(id[i] == -1) dfs(i);
