/* Lowest Common Ancestor using RMQ in O(1) with linear time construction */

/*
    precomp: O(n)
    query: O(1)
    memory: O(n)

    https://codeforces.com/blog/entry/78931
    https://cp-algorithms.com/graph/lca_farachcoltonbender.html
*/

array<int, 2*N> lg2;
for(lg2[0] = -1, i = 1; i < n << 1; i++)
    lg2[i] = lg2[i >> 1] + 1;

int len = (n << 1) - 1, j, k;
int b = max(1, lg2[len] >> 1);
int cntb = (len + b - 1) / b;

vector<int> tin(n), d(n), bmask(cntb), tree;
vector<vector<int>> sparse(lg2[cntb] + 1, vector<int>(cntb));
vector<vector<vector<int>>> best(1 << b-1);
tree.reserve(n << 1);

Y([&](auto dfs, int v, int p) -> void {
    tin[v] = tree.size(); tree.push_back(v);
    for(auto x: g[v]) if(x^p) {
        d[x] = d[v] + 1; dfs(x, v); tree.push_back(v);
    }
})(0, -1);      // dfs(0, -1);

auto lower = [&](int p, int q) {
    return d[tree[p]] < d[tree[q]]? p : q;
};

for(i = 0; i < len; i++) {
    int curb = i / b; j = i % b;
    if(!j or lower(sparse[0][curb], i) == i)
        sparse[0][curb] = i;
    if(j and lower(i-1, i) == i-1)
        bmask[curb] |= 1 << j-1;
}

for(k = 1; k <= lg2[cntb]; k++) {
    for(i = 0; i < cntb; i++) {
        j = i + (1 << k-1);
        sparse[k][i] = sparse[k-1][i];
        if(j < cntb)
            sparse[k][i] = lower(sparse[k-1][i], sparse[k-1][j]);
    }
}

for(int curb = 0; curb < cntb; curb++) {
    int mask = bmask[curb];
    if(best[mask].size()) continue;
    best[mask].resize(b, vector<int>(b));
    for(i = 0; i < b; i++) {
        best[mask][i][i] = i;
        for(j = i+1; j < b; j++) {
            if(b*curb+j >= len) break;
            best[mask][i][j] = lower(b * curb + best[mask][i][j-1], b * curb + j);
            best[mask][i][j] -= b * curb;
        }
    }
}

auto geti = [&](int curb, int l, int r) {
    return best[bmask[curb]][l][r] + b * curb;
};

auto LCA = [&](int u, int v) {
    u = tin[u]; v = tin[v];
    if(u > v) swap(u, v);
    int bu = u / b, bv = v / b;
    if(bu == bv) return tree[geti(bu, u % b, v % b)];
    int res = lower(geti(bu, u % b, b-1), geti(bv, 0, v % b));
    if(bv - bu > 1) {
        int z = lg2[bv - bu - 1];
        res = lower(res, lower(sparse[z][bu + 1], sparse[z][bv - (1 << z)]));
    } return tree[res];
};