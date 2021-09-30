/* Mo's algorithm on trees with weighted nodes */

/*
    Blog:
        https://codeforces.com/blog/entry/43230
        https://codeforces.com/blog/entry/81716
*/

vector<int> depth(n), tin(n), tout(n), id(n << 1), parw(n);
array<vector<int>, LG> anc;
for(auto& x: anc) x.assign(n, -1);

Y([&, t = 0](auto dfs, int v, int p) mutable -> void {
    id[tin[v] = t++] = v;
    anc[0][v] = p;
    for(int k = 1; k < LG; k++)
        if(~anc[k-1][v]) anc[k][v] = anc[k-1][anc[k-1][v]];
    for(auto& x: g[v]) if(x ^ p) {
        depth[x] = depth[v] + 1;
        parw[x] = w; dfs(x, v);
    }
    id[tout[v] = t++] = v;
})(0, -1);

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

vector<Query> queries;
queries.reserve(Q);
for(i = 0; i < Q; i++) {
    int u, v; cin >> u >> v;
    if(tin[--u] > tin[--v]) swap(u, v);
    queries.emplace_back(u == LCA(u, v)? tin[u] + 1 : tout[u], tin[v] + 1, i);
}

sort(queries.begin(), queries.end());

// [l, r)
int l = 0, r = 0;
int64_t cur = 0;
vector<int> active(n), cnt(n);

auto toggle = [&](int v) {
    if(active[v] and !--cnt[a[v]]) cur--;
    else if(!active[v] and !cnt[a[v]]++) cur++;
    active[v] ^= 1;
};

vector<int64_t> ans(Q);
for(auto& q: queries) {
    while(l > q.l)
        toggle(id[--l]);
    while(r < q.r)
        toggle(id[r++]);
    while(l < q.l)
        toggle(id[l++]);
    while(r > q.r)
        toggle(id[--r]);

    if(r <= l) continue;

    ans[q.idx] = cur;
}