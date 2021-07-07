/* Recursive segment tree with lazy propagation (range updates) */

// 0-based indexing [0, n-1] -> ONE = false
// T = Node, U = Lazy
// U = int64_t handles regular range add without having to create a Lazy struct
template<class T, class U = int64_t, bool ONE = true>
class Segtree {
    int N; vector<T> st; vector<U> lazy; vector<bool> pending;

    static int ceil2n(int x) {
        return (1 << 31 - __builtin_clz(x << 1) + !!(x & x-1)) + 2;
    }

    template<class It>
    void build(int node, int L, int R, It beg, It end, bool opt) {
        if(L == R) return st[node] = static_cast<T>(*beg), void();
        int M = L + R >> 1;
        build(node << 1, L, M, beg, beg + (opt? M - L : 0), opt);
        build(node << 1 | 1, M + 1, R, beg + (opt? M - L + 1 : 0), end, opt);
        st[node] = T(st[node << 1], st[node << 1 | 1]);
    }

    void prop(int node, int L, int R) {
        if(L != R) {
            pending[node << 1] = pending[node << 1 | 1] = true;
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
        }
        st[node].apply_lazy(lazy[node], R - L + 1);
        pending[node] = false; lazy[node] = U();
    }

    T Query(int node, int L, int R, int ql, int qr) {
        if(pending[node]) prop(node, L, R);
        if(qr < ql) return T();
        if(ql == L and R == qr) return st[node];
        int M = L + R >> 1;
        return T(Query(node << 1, L, M, ql, min(qr, M)),
                    Query(node << 1 | 1, M + 1, R, max(M + 1, ql), qr));
    }

    void Update(int node, int L, int R, int ul, int ur, const U& val) {
        if(pending[node]) prop(node, L, R);
        if(ur < ul) return;
        if(ul == L and R == ur)
            return lazy[node] += val, prop(node, L, R);
        int M = L + R >> 1;
        Update(node << 1, L, M, ul, min(ur, M), val);
        Update(node << 1 | 1, M + 1, R, max(M + 1, ul), ur, val);
        st[node] = T(st[node << 1], st[node << 1 | 1]);
    }


public:

    // Default value ctor
    // similar to std::vector
    //      Segtree(n) builds n leaves with value T()
    //      Segtree(n, args...) builds n leaves with value T(args...)
    template<class... Args>
    Segtree(int N, Args&&... args)
        : N(N), st(ceil2n(N)), lazy(st.size()), pending(st.size()) {
            T val(forward<Args>(args)...); build(1, ONE, N - !ONE, &val, &val, false);
    }

    // Iterator ctor
    // must be random access (eg: vector<T>::iterator, T *)
    template<typename It,
        typename = enable_if_t<is_same<typename iterator_traits<It>::iterator_category,
                                            random_access_iterator_tag>::value,
                                typename iterator_traits<It>::difference_type>>
    Segtree(It beg, It end)
        : N(end - beg), st(ceil2n(N)), lazy(st.size()), pending(st.size()) {
            build(1, ONE, N - !ONE, beg, end, true);
    }

    // [l, r] inclusive
    T query(int pos) { return Query(1, ONE, N - !ONE, pos, pos); }
    T query(int ql, int qr) { return Query(1, ONE, N - !ONE, ql, qr); }

    // [l, r] inclusive
    // update(ul, ur, args...) -> update(ul, ur, Lazy(args...))
    template<class... Args>
    void update(int ul, int ur, Args&&... args) {
        U val(forward<Args>(args)...);
        Update(1, ONE, N - !ONE, ul, ur, val);
    }

    template<class... Args>
    void update_point(int pos, Args&&... args) {
        update(pos, pos, forward<Args>(args)...);
    }

};

struct Lazy {
    int64_t lzy;
    Lazy(int64_t lzy = 0): lzy(lzy) {}                          // default value
    void operator+=(const Lazy& rhs) { lzy += rhs.lzy; }        // combine with parent lazy
    operator int64_t() const { return lzy; }
};

struct Node {
    using T = int; T val;
    Node(T val = 0): val(val) {}                // default value
    Node(const Node& l, const Node& r)          // merge two nodes
        : val(l.val + r.val) {}
    void apply_lazy(                            // apply lazy
      const Lazy& lazy,                             // change this line to: `int64_t lazy`
      int32_t len                                   // if you do not declare a Lazy struct
    ) { val += lazy; }
    operator T() const { return val; }
};

/*
int32_t main() {
    int N = 1e6;
    Segtree<Node> st1(N);
    Segtree<Node, int64_t, 0> st2(N, 42);

    vector<int> a{ 1, 2, 3, 4, 5, 6 };
    Segtree<Node, Lazy> st3(a.begin(), a.end());

    int arr[] = { 3, 4, 5, 6 };
    Segtree<Node, Lazy, false> st4(arr, arr + 4);

}
*/

/*
    Blog: https://csacademy.com/lesson/segment_trees/
    Hello world: https://cses.fi/problemset/task/1651
    More problems: https://codeforces.com/edu/course/2/lesson/5
*/