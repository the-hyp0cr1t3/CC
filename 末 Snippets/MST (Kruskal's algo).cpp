/* Minimum Spanning Tree - Kruskal's Algorithm */

/*
    https://github.com/the-hyp0cr1t3/CC/blob/master/Beginner%20Topics/%5BS5%5D%20Do%20you%20understand%20the%20graphity%20of%20this%20situation/%5BEP%203%5D%20Spanning%20Trees/%5BPt%202%5D%20Kruskal%27s%20MST.md
*/

struct edge_t {
    int u, v, w;
    edge_t(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const edge_t& other) { return w < other.w; }
    friend ostream& operator<<(ostream& os, edge_t& e) { os << e.u << ' ' << e.v << ' ' << e.w; return os; }
};

vector<int> par(n), sz_(n, 1);
iota(par.begin(), par.end(), 0);

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

vector<edge_t> edges, ans;
// ...
sort(edges.begin(), edges.end());
int cost = 0;

for(auto& e: edges)
    if(merge(e.u, e.v))
        cost += e.w, ans.push_back(e);

