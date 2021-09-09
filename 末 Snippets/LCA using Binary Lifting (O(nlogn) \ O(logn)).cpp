/* Lowest Common Ancestor using Binary lifting */

/*
    precomp: O(nlogn)
    query: O(logn)
    memory: O(nlogn)

    https://cp-algorithms.com/graph/lca_binary_lifting.html
    https://cses.fi/book/book.pdf#page=177
    https://www.topcoder.com/thrive/articles/Range%20Minimum%20Query%20and%20Lowest%20Common%20Ancestor
*/

const int LG = 18;
vector<int> depth(n);
array<vector<int>, LG> anc;
for(auto& x: anc) x.assign(n, -1);

Y([&](auto dfs, int v, int p) -> void {
    anc[0][v] = p;
    for(int k = 1; k < LG; k++)
        if(~anc[k-1][v]) anc[k][v] = anc[k-1][anc[k-1][v]];
    for(auto& x: g[v]) if(x^p) {
        depth[x] = depth[v] + 1; dfs(x, v);
    }
})(0, -1);      // dfs(0, -1);

auto LCA = [&](int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    for(int z = 0; z < LG; z++)
        if(depth[u]-depth[v] >> z & 1) u = anc[z][u];
    if(u == v) return u;
    for(int z = LG-1; ~z; z--)
        if(anc[z][u] ^ anc[z][v])
            u = anc[z][u], v = anc[z][v];
    return anc[0][u];
};

