/* Query struct - Hilbert ordering */

/*
    https://codeforces.com/blog/entry/61203
*/

int64_t hilbertorder(int x, int y) {
    static constexpr int LG = 31 - __builtin_clz(N) + !!(N & N-1);
    static constexpr int maxn = 1 << LG;

    int64_t d = 0;
    for(int s = 1 << (LG - 1); s; s >>= 1) {
        bool rx = x & s, ry = y & s;
        d = d << 2 | rx * 3 ^ static_cast<int>(ry);
        if(!ry) {
            if(rx) x = maxn - x, y = maxn - y;
            swap(x, y);
        }
    } return d;
}

struct Query {
    int l, r, idx;
    int64_t ord;

    Query(int l, int r, int idx)
        : l(l), r(r), idx(idx), ord(hilbertorder(l + 1, r)) {}

    bool operator<(const Query& o) const {
        return ord < o.ord;
    }
};