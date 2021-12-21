/* Recursive segment tree with point updates */

// 0-based indexing [0, n-1] -> ONE = false
// T = Node
template<class T, bool ONE = true>
class Segtree {
    int N; vector<T> st;

    template<typename V>
    void build(int node, int L, int R, const vector<V>& a) {
        if(L == R) return st[node] = static_cast<T>(a[L - ONE]), void();
        int M = L + R >> 1;
        build(node << 1, L, M, a);
        build(node << 1 | 1, M + 1, R, a);
        st[node] = T(st[node << 1], st[node << 1 | 1]);
    }

    void Update(int node, int L, int R, int pos, typename T::V val) {
        if(L == R) return st[node].upd(val);
        int M = L + R >> 1;
        pos <= M? Update(node << 1, L, M, pos, val)
                    : Update(node << 1 | 1, M + 1, R, pos, val);
        st[node] = T(st[node << 1], st[node << 1 | 1]);
    }

    T Query(int node, int L, int R, int ql, int qr) {
        if(ql == L and R == qr) return st[node];
        int M = L + R >> 1;
        return qr <= M? Query(node << 1, L, M, ql, qr)
                        : M < ql? Query(node << 1 | 1, M + 1, R, ql, qr)
                            : T(Query(node << 1, L, M, ql, M),
                                    Query(node << 1 | 1, M + 1, R, M + 1, qr));
    }

    int Queryk(int node, int L, int R, typename T::V val) {
        if(L == R) return val <= st[node]? L : -1;
        int M = L + R >> 1;
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
    void update(int pos, typename T::V val) { Update(1, ONE, N - !ONE, pos, val); }

    // [l, r] inclusive
    T query(int pos) { return Query(1, ONE, N - !ONE, pos, pos); }
    T query(int l, int r) { return Query(1, ONE, N - !ONE, l, r); }
    int queryk(typename T::V val) { return Queryk(1, ONE, N - !ONE, val); }

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
    Blog: https://csacademy.com/lesson/segment_trees/
    Hello world: https://cses.fi/problemset/task/1648
    More problems: https://codeforces.com/edu/course/2/lesson/4
*/