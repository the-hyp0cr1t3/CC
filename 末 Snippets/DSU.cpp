// short implementation
vector<int> par(n), sz_(n, 1);
iota(all(par), 0);

auto getpar = [&] (int x) {
    int pp = x;
    while(par[pp] != pp)
        pp = par[pp];
    while(par[x] != x) {
        int z = par[x];
        par[x] = pp;
        x = z;
    }
    return pp;        
};

auto merge = [&] (int x, int y) {
    x = getpar(x);
    y = getpar(y);
    if (x == y) return false;
    if (sz_[x] < sz_[y]) swap(x, y);
    par[y] = x, sz_[x] += sz_[y];
    return true;
};

/* -------------------------------------------------- */
// DSU struct
struct DSU {
    int n, par[N], size[N], roots[N], rootID[N], rootcnt;
    DSU(int Q) : n(Q), rootcnt(Q) {
        iota(par, par+n, 0);
        fill(size, size+n, 1);
    }

    int getpar(int x) {
        int pp = x;
        while(par[pp] != pp)
            pp = par[pp];
        while(par[x] != x) {
            int z = par[x];
            par[x] = pp;
            x = z;
        }
        return pp;
    }

    bool merge(int x, int y) {
        x = getpar(x);
        y = getpar(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        par[y] = x, size[x] += size[y];
        rootcnt--;
        return true;
    }

    bool same(int x, int y) {
        return getpar(x) == getpar(y);
    }
    
    void getRoots() {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if (par[i] != i) continue;
            rootID[i] = cnt;
            roots[cnt++] = i;
        }
        assert(cnt == rootcnt);
    }
};

