/* Query struct - canonical */

struct Query {
    static const int block_size = 1.6 * sqrt(N) + 1;
    // static const int block_size = N / sqrt(Q) + 1;

    int l, r, idx, b;
    Query(int l, int r, int idx)
        : l(l), r(r), idx(idx), b(l / block_size) {}

    bool operator<(const Query& o) const {
        return b ^ o.b? l < o.l : b & 1? r > o.r : r < o.r;
    }
};