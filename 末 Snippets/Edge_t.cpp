struct edge_t {
    int u, v, w;
    edge_t(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const edge_t& other) { return w < other.w; }
    friend ostream& operator<<(ostream& os, edge_t& e) { os << e.u << ' ' << e.v << ' ' << e.w; return os; }
};

