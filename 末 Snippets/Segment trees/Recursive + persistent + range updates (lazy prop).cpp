/* Persistent segment tree with lazy propagation (range updates) */

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

    void prop(int node, int L, int R) {
        if(L != R) {
            int lc = create(st[node].lc);
            int rc = create(st[node].rc);
            st[node].lc = lc; st[node].rc = rc;
            st[lc].pending = st[rc].pending = true;
            st[lc].lazy += st[node].lazy;
            st[rc].lazy += st[node].lazy;
        }
        st[node].apply_lazy(R - L + 1);
        st[node].pending = false; st[node].lazy = typename T::L();
    }

    void Update(int node, int L, int R, int ul, int ur, const typename T::L& val) {
        if(st[node].pending) prop(node, L, R);
        if(ur < ul) return;
        if(ul == L and R == ur)
            return st[node].lazy += val, prop(node, L, R);
        int M = L + R >> 1, lc = st[node].lc, rc = st[node].rc;

        lc = create(lc);
        Update(lc, L, M, ul, min(ur, M), val);

        rc = create(rc);
        Update(rc, M + 1, R, max(M + 1, ul), ur, val);

        st[node] = T(st[lc], st[rc]);
        st[node].lc = lc; st[node].rc = rc;
    }

    T Query(int node, int L, int R, int ql, int qr) {
        if(st[node].pending) prop(node, L, R);
        if(qr < ql) return T();
        if(ql == L and R == qr) return st[node];
        int M = L + R >> 1;
        return T(Query(st[node].lc, L, M, ql, min(qr, M)),
                    Query(st[node].rc, M + 1, R, max(M + 1, ql), qr));
    }

    int Queryk(int node, int L, int R, typename T::V val) {
        if(st[node].pending) prop(node, L, R);
        if(L == R) return val <= st[node]? L : -1;
        int M = L + R >> 1, lc = st[node].lc, rc = st[node].rc;
        if(st[lc].pending) prop(lc, L, M);
        return val <= st[lc]? Queryk(lc, L, M, val) : Queryk(rc, M + 1, R, val - st[lc]);
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

    // [l, r] inclusive; in_place = true -> replace version[ver] with new root
    // ver = -1 -> use the latest version
    // update(ver, in_place, ul, ur, args...) -> update(ver, in_place, ul, ur, Lazy(args...))
    template<class... Args>
    int update_range(int ver, bool in_place, int l, int r, Args&&... args) {
        if(ver == -1) ver = version_cnt - 1;
        if(!in_place)
            version.push_back(create(version[ver])), ver = version_cnt++;
        Update(version[ver], ONE, N - !ONE, l, r, typename T::L(forward<Args>(args)...));
        return ver;
    }

    template<class... Args>
    int update_point(int ver, bool in_place, int pos, Args&&... args) {
        return update_range(ver, in_place, pos, pos, forward<Args>(args)...);
    }

    // [l, r] inclusive
    // ver = -1 -> use the latest version
    T query(int ver, int pos) { return query(ver, pos, pos); }
    T query(int ver, int l, int r) {
        if(ver == -1) ver = version_cnt - 1;
        return Query(version[ver], ONE, N - !ONE, l, r);
    }

    int queryk(int ver, typename T::V val) {
        if(ver == -1) ver = version_cnt - 1;
        return Queryk(version[ver], ONE, N - !ONE, val);
    }
};

struct Node {
    using V = int64_t;
    // using L = int64_t;                       // can replace lazy struct with an int/int64_t
    using L = struct Lazy {
        V lzy;
        Lazy(V lzy = 0): lzy(lzy) {}            // default value
        operator V() const { return lzy; }
        void operator+=(const Lazy& rhs) { lzy += rhs.lzy; }    // combine with other lazy
    };

    int lc{-1}, rc{-1};
    bool pending{false};
    V val; L lazy{};
    Node(V val = 0): val(val) {}                // default values
    Node(const Node& l, const Node& r)          // merge two nodes
        : val(l.val + r.val) {}
    void apply_lazy(int len) { val += lazy * len; }     // update node
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
    Blog:
    Hello world:
    More problems:
*/