/* Persistent segment tree with point updates */

// 0-based indexing [0, n-1] -> ONE = false
// T = Node
template<class T, bool ONE = true>
class Segtree {
    struct Node { int lc{-1}, rc{-1}; T info; };

    int N, size{1}, version_cnt{0};
    vector<Node> st; vector<int> version;

    static int ceil2n(int x) {
        return (1 << 31 - __builtin_clz(x << 1) + !!(x & x-1)) + 2;
    }

    int create(int id = 0) {
        st.emplace_back(st[id]);
        return size++;
    }

    template<typename It>
    void build(int node, int L, int R, It beg, It end, bool opt) {
        if(L == R)
            return st[node].info = static_cast<T>(*beg), void();
        int M = L + R >> 1;

        int lc = st[node].lc = create();
        build(lc, L, M, beg, beg + (opt? M - L : 0), opt);

        int rc = st[node].rc = create();
        build(rc, M + 1, R, beg + (opt? M - L + 1 : 0), end, opt);

        st[node].info = T(st[lc].info, st[rc].info);
    }

    T Query(int node, int L, int R, int ql, int qr) {
        if(ql == L and R == qr) return st[node].info;
        int M = L + R >> 1;
        return qr <= M? Query(st[node].lc, L, M, ql, qr)
                        : M < ql? Query(st[node].rc, M + 1, R, ql, qr)
                            : T(Query(st[node].lc, L, M, ql, M),
                                    Query(st[node].rc, M + 1, R, M + 1, qr));
    }

    void Update(int node, int L, int R, int pos, int64_t val) {
        if(L == R) return st[node].info.upd(val);
        int M = L + R >> 1, lc = st[node].lc, rc = st[node].rc;
        if(pos <= M) {
            lc = create(lc); st[node].lc = lc;
            Update(lc, L, M, pos, val);
        } else {
            rc = create(rc); st[node].rc = rc;
            Update(rc, M + 1, R, pos, val);
        }

        st[node].info = T(st[lc].info, st[rc].info);
    }

public:

    // Default value ctor
    // similar to std::vector
    //      Segtree(n) builds n leaves with value T()
    //      Segtree(n, args...) builds n leaves with value T(args...)
    template<class... Args>
    Segtree(int N, Args&&... args): N(N), st(1) {
        st.reserve(ceil2n(N));
        T val(forward<Args>(args)...);
        version.push_back(create()); version_cnt++;
        build(1, ONE, N - !ONE, &val, &val, false);
    }

    // Iterator ctor
    // must be random access (eg: vector<T>::iterator, T *)
    template<typename It,
        typename = enable_if_t<is_same<typename iterator_traits<It>::iterator_category,
                                            random_access_iterator_tag>::value,
                                typename iterator_traits<It>::difference_type>>
    Segtree(It beg, It end): N(end - beg), st(1) {
        st.reserve(ceil2n(N));
        version.push_back(create()); version_cnt++;
        build(1, ONE, N - !ONE, beg, end, true);
    }

    // ver = -1 -> use the latest version
    T query(int ver, int qpos) {
        if(ver == -1) ver = version_cnt - 1;
        return Query(version[ver], ONE, N - !ONE, qpos, qpos);
    }

    // [l, r] inclusive
    T query(int ver, int ql, int qr) {
        if(ver == -1) ver = version_cnt - 1;
        return Query(version[ver], ONE, N - !ONE, ql, qr);
    }

    // copies version ver and returns copy's id
    int copy(int ver) {
        version.push_back(create(version[ver]));
        return version_cnt++;
    }

    int update(int ver, int pos, int64_t val) {
        if(ver == -1) ver = version_cnt - 1;
        version.push_back(create(version[ver]));
        Update(version[version_cnt], ONE, N - !ONE, pos, val);
        return version_cnt++;
    }

};

struct Node {
    using T = int; T val;
    Node(T val = 0): val(val) {}                // default values
    Node(const Node& l, const Node& r)          // merge two nodes
        : val(l.val + r.val) {}
    void upd(T delta) { val += delta; }         // update node
    operator T() const { return val; }
};

/*
int32_t main() {
    int N = 1e6;
    Segtree<Node> st1(N);
    Segtree<Node, 0> st2(N, 42);

    vector<int> a{ 1, 2, 3, 4, 5, 6 };
    Segtree<Node> st3(a.begin(), a.end());

    int arr[] = { 3, 4, 5, 6 };
    Segtree<Node, false> st4(arr, arr + 4);

}
*/

/*
    Blog: https://codeforces.com/blog/entry/92304
    Hello world: https://cses.fi/problemset/task/1737
    More problems:
*/
