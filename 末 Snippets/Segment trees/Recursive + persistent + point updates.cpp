/* Persistent segment tree with point updates */

// 0-based indexing [0, n-1] -> ONE = false
// T = Node
template<class T, bool ONE = true>
class Segtree {
    int N, size{1}, version_cnt{0};
    vector<T> st; vector<int> version;

    int create(int id = 0) {
        st.emplace_back(st[id]);
        return size++;
    }

    template<typename A>
    void build(int node, int L, int R, const vector<A>& a) {
        if(L == R) return st[node] = static_cast<T>(a[L - ONE]), void();
        int M = L + R >> 1;
        int lc = create();
        build(lc, L, M, a);
        int rc = create();
        build(rc, M + 1, R, a);
        st[node] = T(st[lc], st[rc]);
        st[node].lc = lc; st[node].rc = rc;
    }

    void Update(int node, int L, int R, int pos, typename T::V val) {
        if(L == R) return st[node].upd(val);
        int M = L + R >> 1, lc = st[node].lc, rc = st[node].rc;
        pos <= M? (lc = create(lc), Update(lc, L, M, pos, val))
                    : (rc = create(rc), Update(rc, M + 1, R, pos, val));
        st[node] = T(st[lc], st[rc]);
        st[node].lc = lc; st[node].rc = rc;
    }

    T Query(int node, int L, int R, int ql, int qr) {
        if(ql == L and R == qr) return st[node];
        int M = L + R >> 1, lc = st[node].lc, rc = st[node].rc;
        return qr <= M? Query(lc, L, M, ql, qr)
                        : M < ql? Query(rc, M + 1, R, ql, qr)
                            : T(Query(lc, L, M, ql, M),
                                    Query(rc, M + 1, R, M + 1, qr));
    }

    int Queryk(int v1, int v2, int L, int R, typename T::V val) {
        if(L == R) return val <= st[v2] - st[v1]? L : -1;
        int M = L + R >> 1;
        int lc1 = st[v1].lc, rc1 = st[v1].rc;
        int lc2 = st[v2].lc, rc2 = st[v2].rc;
        typename T::V left_child = st[lc2] - st[lc1];
        return val <= left_child?
                    Queryk(lc1, lc2, L, M, val)
                        : Queryk(rc1, rc2, M + 1, R, val - left_child);
    }

public:

    // Vector ctor
    template<typename A>
    Segtree(const vector<A>& a): N(a.size()), st(1) {
        st.reserve((1 << 31 - __builtin_clz(N << 1) + !!(N & N-1)) + 2);
        version.push_back(create()); version_cnt++;
        build(1, ONE, N - !ONE, a);
    }

    // Default value ctor
    // similar to std::vector
    //      Segtree(n) builds n leaves with value T()
    //      Segtree(n, args...) builds n leaves with value T(args...)
    template<class... Args>
    Segtree(int n, Args&&... args): Segtree(vector<T>(n, T(forward<Args>(args)...))) {}

    // copies version ver and returns copy's id
    int copy(int ver) {
        version.push_back(create(version[ver]));
        return version_cnt++;
    }

    // [l, r] inclusive
    // ver = -1 -> use the latest version
    // in_place = true -> replace version[ver] with new root
    template<class... Args>
    int update_point(int ver, bool in_place, int pos, Args&&... args) {
        if(ver == -1) ver = version_cnt - 1;
        if(!in_place)
            version.push_back(create(version[ver])),ver = version_cnt++;
        Update(version[ver], ONE, N - !ONE, pos, typename T::V(forward<Args>(args)...));
        return ver;
    }

    // ver = -1 -> use the latest version
    T query(int ver, int pos) { return query(ver, pos, pos); }
    T query(int ver, int l, int r) {
        if(ver == -1) ver = version_cnt - 1;
        return Query(version[ver], ONE, N - !ONE, l, r);
    }

    int queryk(int v1, int v2, typename T::V val) {
        return Queryk(version[v1], version[v2], ONE, N - !ONE, val);
    }
};

struct Node {
    using V = int64_t;
    V val;
    Node(V val = 0): val(val) {}            // default values
    Node(const Node& l, const Node& r)      // merge two nodes
        : val(l.val + r.val) {}
    void upd(V delta) { val = delta; }      // update node
    operator V() const { return val; }
};

/*
int32_t main() {
    int N = 1e6;
    Segtree<Node> st1(N);
    Segtree<Node, 0> st2(N, 42);

    vector<int> a{ 1, 2, 3, 4, 5, 6 };
    Segtree<Node> st3(a);
}
*/

/*
    Blog: https://codeforces.com/blog/entry/92304
    Hello world: https://cses.fi/problemset/task/1737
    More problems:
*/