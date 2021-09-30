/* Strongly Connected Components - Tarjan's algorithm */

/*
    Algorithms Live:
        https://www.youtube.com/watch?v=z9oOadBgO9I&ab_channel=AlgorithmsLive
*/

int sccount = 0;
vector<int> id(n, -1), low(n), onstack(n), comp(n);
stack<int> st;

// Tarjan's SCC, produces reverse topsort by comp id
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