/* Strongly Connected Components - Kosaraju's algorithm */

/*
    https://www.youtube.com/watch?v=z9oOadBgO9I&ab_channel=AlgorithmsLive
    https://cp-algorithms.com/graph/strongly-connected-components.html
*/

int sccount = 0;
vector<vector<int>> g(n), rg(n);
vector<int> comp(n, -1), order;

auto dfs = Y([&](auto dfs, int v, int k, const auto& gr) -> void {
    comp[v] = k;
    for(auto& x: gr[v])
        if(comp[x] == -1) dfs(x, k, gr);
    if(k == -2) order.push_back(v);
});

order.reserve(n);
for(i = 0; i < n; i++)
    if(comp[i] == -1) dfs(i, -2, g);

comp.assign(n, -1);
while(!order.empty()) {
    dfs(order.back(), sccount++, rg);
    while(!order.empty() and ~comp[order.back()])
        order.pop_back();
}