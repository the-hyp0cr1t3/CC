/* Mo's algorithm */

/*
    Blog:
        https://codeforces.com/blog/entry/88494
        https://codeforces.com/blog/entry/81716
*/

vector<Query> queries;
queries.reserve(Q);
for(i = 0; i < Q; i++) {
    int l, r; cin >> l >> r;
    queries.emplace_back(--l, r, i);
}

sort(queries.begin(), queries.end());

// [l, r)
int l = 0, r = 0;
int64_t cur = 0;

auto update = [&](int val, int delta) {

};

vector<int64_t> ans(Q);
for(auto& q: queries) {
    while(l > q.l)
        update(a[--l], +1);
    while(r < q.r)
        update(a[r++], +1);
    while(l < q.l)
        update(a[l++], -1);
    while(r > q.r)
        update(a[--r], -1);
    ans[q.idx] = cur;
}