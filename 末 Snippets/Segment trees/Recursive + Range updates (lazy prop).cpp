/* Recursive segment tree with lazy propagation (range updates) */

// 0-based indexing [0, n-1] -> ONE = false
// T = Node
template<class T, bool ONE = true>
class Segtree {
    int N; vector<T> st;

    template<typename A>
    void build(int node, int L, int R, const vector<A>& a) {
        if(L == R) return st[node] = static_cast<T>(a[L - ONE]), void();
        int M = L + R >> 1;
        build(node << 1, L, M, a);
        build(node << 1 | 1, M + 1, R, a);
        st[node] = T(st[node << 1], st[node << 1 | 1]);
    }

    void prop(int node, int L, int R) {
        if(L != R) {
            st[node << 1].pending = st[node << 1 | 1].pending = true;
            st[node << 1].lazy += st[node].lazy;
            st[node << 1 | 1].lazy += st[node].lazy;
        }
        st[node].apply_lazy(R - L + 1);
        st[node].pending = false; st[node].lazy = typename T::L();
    }

    void Update(int node, int L, int R, int ul, int ur, const typename T::L& val) {
        if(st[node].pending) prop(node, L, R);
        if(ur < ul) return;
        if(ul == L and R == ur)
            return st[node].lazy += val, prop(node, L, R);
        int M = L + R >> 1;
        Update(node << 1, L, M, ul, min(ur, M), val);
        Update(node << 1 | 1, M + 1, R, max(M + 1, ul), ur, val);
        st[node] = T(st[node << 1], st[node << 1 | 1]);
    }

    T Query(int node, int L, int R, int ql, int qr) {
        if(st[node].pending) prop(node, L, R);
        if(qr < ql) return T();
        if(ql == L and R == qr) return st[node];
        int M = L + R >> 1;
        return T(Query(node << 1, L, M, ql, min(qr, M)),
                    Query(node << 1 | 1, M + 1, R, max(M + 1, ql), qr));
    }

    int Queryk(int node, int L, int R, typename T::V val) {
        if(st[node].pending) prop(node, L, R);
        if(L == R) return val <= st[node]? L : -1;
        int M = L + R >> 1;
        if(st[node << 1].pending) prop(node << 1, L, M);
        return val <= st[node << 1]?
                    Queryk(node << 1, L, M, val)
                        : Queryk(node << 1 | 1, M + 1, R, val - st[node << 1]);
    }

public:

    // Vector ctor
    template<typename V>
    Segtree(const vector<V>& a): N(a.size()) {
        st.resize((1 << 31 - __builtin_clz(N << 1) + !!(N & N-1)) + 2);
        build(1, ONE, N - !ONE, a);
    }

    // Default value ctor
    // similar to std::vector
    //      Segtree(n) builds n leaves with value T()
    //      Segtree(n, args...) builds n leaves with value T(args...)
    template<class... Args>
    Segtree(int n, Args&&... args): Segtree(vector<T>(n, T(forward<Args>(args)...))) {}

    // [l, r] inclusive
    // update(ul, ur, args...) -> update(ul, ur, Lazy(args...))
    template<class... Args>
    void update_range(int l, int r, Args&&... args) {
        Update(1, ONE, N - !ONE, l, r, typename T::L(forward<Args>(args)...));
    }

    template<class... Args>
    void update_point(int pos, Args&&... args) {
        update_range(pos, pos, forward<Args>(args)...);
    }

    // [l, r] inclusive
    T query(int pos) { return Query(1, ONE, N - !ONE, pos, pos); }
    T query(int l, int r) { return Query(1, ONE, N - !ONE, l, r); }
    int queryk(typename T::V val) { return Queryk(1, ONE, N - !ONE, val); }

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
    Blog: https://csacademy.com/lesson/segment_trees/
    Hello world: https://cses.fi/problemset/task/1651
    More problems: https://codeforces.com/edu/course/2/lesson/5
*/