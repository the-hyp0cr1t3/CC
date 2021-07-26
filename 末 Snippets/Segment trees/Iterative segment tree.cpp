/* Iterative segment tree with point updates */

int main() {
    int i, n, Q;
    cin >> n >> Q;

    vector<int64_t> seg(n << 1);
    for(i = 0; i < n; i++)
        cin >> seg[i + n];

    // build
    for(i = n-1; i; i--)
        seg[i] = seg[i << 1] + seg[i << 1 | 1];

    // query [l, r)
    auto query = [n, &seg](int l, int r) {
        int64_t res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) res += seg[l++];
            if(r&1) res += seg[--r];
        } return res;
    };

    // update pos, val
    auto update = [n, &seg](int pos, int val) {
        for(seg[pos += n] = val; pos >>= 1; )
            seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
    };

    while(Q--) {
        int o; cin >> o;
        if(o == 1) {
            int pos, val; cin >> pos >> val;
            update(--pos, val);
        } else {
            int l, r; cin >> l >> r;
            cout << query(--l, r) << '\n';
        }
    }
}

/*
    Blog: https://codeforces.com/blog/entry/18051
    Hello world: https://cses.fi/problemset/task/1648/
    More problems: https://codeforces.com/edu/course/2/lesson/4
    Lazy prop variant: https://codeforces.com/contest/343/submission/24869698
                       https://codeforces.com/contest/1550/submission/122582660
*/