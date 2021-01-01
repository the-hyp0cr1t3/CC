/* Lowest Common Ancestor */

/* Inspired by [tmwilliamlin168](https://codeforces.com/profile/tmwilliamlin168) */
// O(NlogN) precomp, O(logN) per query, O(NlogN) space
// (https://cp-algorithms.com/graph/lca_binary_lifting.html)
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

/* -------------------------------------------------- */
/* LCA using Sparse Table */
// O(N) precomp, O(1) per query, O(N) space
// (https://cp-algorithms.com/graph/lca_farachcoltonbender.html)
int n;
vector<int> g[N];   // adjacency list

int tin[N], d[N], lg2[2*N];
vector<int> tree, bmask;
vector<vector<int>> sparse;
vector<vector<vector<int>>> best;
int len, b, cntb;

void dfs(int v, int p) {
    tin[v] = sz(tree); tree.pb(v);
    for(auto x: g[v]) { 
        if(x == p) continue;
        d[x] = d[v] + 1;
        dfs(x, v); tree.pb(v);
    }
}

bool lower(int p, int q) {
    return d[tree[p]] < d[tree[q]]? p : q;
}

void precomp() {
    int i, j, k;
    len = 2*n-1; lg2[0] = -1;
    for(i = 1; i <= len; i++) 
        lg2[i] = lg2[i/2] + 1;

    b = max(1, lg2[len]/2);
    cntb = (len+b-1)/b;

    bmask.resize(cntb); best.resize(1<<b-1);
    sparse.resize(lg2[cntb]+1, vector<int>(cntb));
    tree.reserve(len);

    dfs(0, -1);

    for(i = 0; i < len; i++) {
        int curb = i/b; j = i%b;
        if(!j or lower(sparse[0][curb], i) == i)
            sparse[0][curb] = i;
        if(j and lower(i-1, i) == i-1)
            bmask[curb] |= 1<<j-1;
    }

    for(k = 1; k <= lg2[cntb]; k++) {
        for(i = 0; i < cntb; i++) {
            j = i + (1<<k-1);
            sparse[k][i] = sparse[k-1][i];
            if(j < cntb)
                sparse[k][i] = lower(sparse[k-1][i], sparse[k-1][j]);
        }
    }

    for(int curb = 0; curb < cntb; curb++) {
        int mask = bmask[curb];
        if(sz(best[mask])) continue;
        best[mask].resize(b, vector<int>(b));
        for(i = 0; i < b; i++) {
            best[mask][i][i] = i;
            for(j = i+1; j < b; j++) {
                if(b*curb+j >= len) break;
                best[mask][i][j] = lower(b*curb+best[mask][i][j-1], b*curb+j);
                best[mask][i][j] -= b*curb;
            }
        }
    }
}

int geti(int curb, int l, int r) {
    return best[bmask[curb]][l][r] + b*curb;
}

int LCA(int u, int v) {
    u = tin[u]; v = tin[v];
    if(u > v) swap(u, v);
    int bu = u/b, bv = v/b;
    if(bu == bv)
        return tree[geti(bu, u%b, v%b)];
    int res = lower(geti(bu, u%b, b-1), geti(bv, 0, v%b));
    if(bv-bu > 1) {
        int z = lg2[bv-bu-1];
        res = lower(res, lower(sparse[z][bu+1], sparse[z][bv-(1<<z)]));
    } return tree[res];
}

// precomp(); int lca = LCA(u, v);
