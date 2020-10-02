// (https://codeforces.com/contest/776/submission/94484305)

int vis[2*N], comp[2*N], assignment[N];
vector<int> g[2*N], rg[2*N], order;

// (p ∨ q) meaning at least one is true
void addedge(int p, int q) {
// (¬p → q) ∧ (¬q → p)
    g[p^1].pb(q); g[q^1].pb(p);
    rg[q].pb(p^1); rg[p].pb(q^1);
}

// (p ⊕ q) meaning exactly one is true
void xoredge(int p, int q) {
// (p ∨ q) ∧ (¬p ∨ ¬q)
    addedge(p, q); addedge(p^1, q^1);
}

// (p ↔ q) both are true or both are false
void biconditionaledge(int p, int q) {
// (p → q) ∧ (q → p) ≡ (p ⊕ ¬q)
    xoredge(p, q^1);
}

void dfs1(int v) {
    vis[v] = 1;
    for(auto& x: g[v])
        if(!vis[x]) dfs1(x);
    order.pb(v);
}

void dfs2(int v, int k) {
    comp[v] = k;
    for(auto& x: rg[v])
        if(comp[x] == -1) dfs2(x, k);
}

// i is represented by 2*i, ¬i is represented by 2*i+1
bool is_sat(int n) {
    memset(comp, -1, sizeof(comp));
    order.reserve(2*n);
    for(int i = 0; i < 2*n; i++)
        if(!vis[i]) dfs1(i);

    reverse(all(order));
    int sccnt = 0;
    for(auto& v: order)
        if(comp[v] == -1)
            dfs2(v, sccnt++);

    for(int i = 0; i < n; i++) {
        if(comp[i<<1] == comp[i<<1|1]) return false;
        // take topologically later option
        assignment[i] = comp[i<<1] > comp[i<<1|1];
    } return true;
}
