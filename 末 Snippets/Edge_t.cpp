/* Edge struct */

struct edge_t {
    int u{-1}, v{-1}; int64_t w{0};
    edge_t() = default;
    edge_t(int u, int v, int64_t w = 0) : u(u), v(v), w(w) {}
    bool operator<(const edge_t& other) { return w < other.w; }
    friend ostream& operator<<(ostream& os, const edge_t& e) { os << e.u << ' ' << e.v << ' ' << e.w; return os; }
};

/* vector<edge_t> edges;
   edges.emplace_back(2, 3, 123456);
   edges.emplace_back(1, 2, 134);
   sort(edges.begin(), edges.end());
*/
