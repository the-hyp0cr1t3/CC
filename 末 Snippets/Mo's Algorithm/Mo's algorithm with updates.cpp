/* Mo's algorithm with updates */

/*
    https://codeforces.com/blog/entry/72690
*/

struct Query {
    static const int block_size = pow(N, 0.66) + 1;     // O(N ^ 5/3) when N ≈ Q

    int l, r, t, idx; tuple<int, int, int> cmp;
    Query(int l, int r, int t, int idx)
        : l(l), r(r), t(t), idx(idx), cmp(
             l / block_size,
            (l / block_size & 1? r / block_size : -r / block_size),
            (r / block_size & 1? t : -t)
        ) {}

    bool operator<(const Query& o) const {
        return cmp < o.cmp;
    }
};

vector<Query> queries;
vector<tuple<int, int, int>> updates; // <pos, old, new>
queries.reserve(Q) updates.reserve(Q);

while(Q--) {
    int type; cin >> type;
    if(type == 1) {
        int l, r; cin >> l >> r;
        queries.emplace_back(--l, r, updates.size(), queries.size());
    } else {
        int pos, val; cin >> pos >> val; --pos;
        updates.emplace_back(pos, a[pos], val); a[pos] = val;
    }
} sort(queries.begin(), queries.end());

// [l, r)
int l = 0, r = 0, t = updates.size();
int64_t cur = 0;

auto update = [&](int val, int delta) {

};

auto changever = [&](int t, int dir, int l, int r) {
    auto [pos, old, nw] = updates[t];
    if(dir == -1) swap(old, nw);
    if(l <= pos and pos < r)
        update(old, -1), update(nw, +1);
    a[pos] = nw;
};

vector<int64_t> ans(queries.size());
for(auto& q: queries) {
    while(l > q.l)
        update(a[--l], +1);
    while(r < q.r)
        update(a[r++], +1);
    while(l < q.l)
        update(a[l++], -1);
    while(r > q.r)
        update(a[--r], -1);
    while(t < q.t)
        changever(t++, +1, l, r);
    while(t > q.t)
        changever(--t, -1, l, r);
    ans[q.idx] = cur;
}