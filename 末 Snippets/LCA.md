Inspired by [tmwilliamlin168](https://codeforces.com/profile/tmwilliamlin168)
```c++
const int LG = 20;
int d[N], anc[LG][N];
vector<int> g[N];

void makeG() {
    for(i = 0; i < n-1; i++) {
        int u, v;
        re(u, v);
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int v, int p) {
    anc[0][v] = p;
    for(int k = 1; k < LG; k++) 
        anc[k][v] = ~anc[k-1][v]? anc[k-1][anc[k-1][v]] : -1;
    for(auto& x: g[v]) {
        if(x == p) continue;
        d[x] = d[v]+1;
        dfs(x, v);
    }
}

int LCA(int u, int v) {
    if(d[u] < d[v])
        swap(u, v);
    for(int z = LG-1; ~z; --z) 
        if(d[u]-(1<<z) >= d[v])
            u = anc[z][u];
    if(u == v)
        return u;
    for(int z = LG-1; ~z; --z)
        if(anc[z][u]^anc[z][v])
            u = anc[z][u], v = anc[z][v];
    return anc[0][u];
}

```

LCA Sparse Table:
```c++
const int K = 20;
int n, tim = 0, height_of[K][2*N], node_of[K][2*N], tin[N], tout[N], d[N];
vector<int> g[N];

int log(int x) {
    return 31 - __builtin_clz(x);
}

void build() {
    int kmax = log(n);
    for(int k = 1; k <= kmax; k++) {
        for(int i = 0; i+(1<<k) <= tim; i++) {
            if(height_of[k-1][i] <= height_of[k-1][i+(1<<(k-1))]) {
                height_of[k][i] = height_of[k-1][i];
                node_of[k][i] = node_of[k-1][i];
            }
            else {
                height_of[k][i] = height_of[k-1][i+(1<<(k-1))];
                node_of[k][i] = node_of[k-1][i+(1<<(k-1))];
            }
        }
    }
}

int LCA(int u, int v) {
    int l = tin[u], r = tin[v];
    if(l > r) swap(l, r), swap(u, v);
    int k = log(r-l+1);
    r = r-(1<<k)+1;
    return height_of[k][l] <= height_of[k][r]? node_of[k][l] : node_of[k][r];
}

void makeG() {
    for(int i = 0; i < n-1; i++) {
        int u, v;
        re(u, v);
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void euler_twour(int v, int p, int h) {
    d[v] = h;
    height_of[0][tim] = d[v];
    node_of[0][tim] = v;
    tin[v] = tout[v] = tim;
    tim++;
    for(auto x: g[v]) {
        if(x^p) {
            euler_twour(x, v, h+1);
            height_of[0][tim] = d[v];
            node_of[0][tim] = v;
            tout[v] = tim;
            tim++;
        }
    }
}

// euler_twour(0, -1, 0);
// build();

lca
```