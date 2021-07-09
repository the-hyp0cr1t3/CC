/* Persistent segment tree with lazy propagation (range updates) */

// 0-based indexing [0, n-1] -> ONE = false
// T = Node, U = Lazy
// U = int64_t handles regular range add without having to create a Lazy struct
template<class T, class U = int64_t, bool ONE = true>
class Segtree {
    struct Node {
        int lc{-1}, rc{-1};
        bool pending{false};
        T info; U lazy{};
    };

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
        
        int lc = create(); st[node].lc = lc;
        build(lc, L, M, beg, beg + (opt? M - L : 0), opt);

        int rc = create(); st[node].rc = rc;
        build(rc, M + 1, R, beg + (opt? M - L + 1 : 0), end, opt);

        st[node].info = T(st[lc].info, st[rc].info);
    }

    void prop(int node, int L, int R) {
        if(L != R) {
            int lc = st[node].lc = create(st[node].lc);
            int rc = st[node].rc = create(st[node].rc);
            st[lc].pending = st[rc].pending = true;
            st[lc].lazy += st[node].lazy;
            st[rc].lazy += st[node].lazy;
        }
        st[node].info.apply_lazy(st[node].lazy, R - L + 1);
        st[node].pending = false; st[node].lazy = U();
    }

    T Query(int node, int L, int R, int ql, int qr) {
        if(st[node].pending) prop(node, L, R);
        if(qr < ql) return T();
        if(ql == L and R == qr) return st[node].info;
        int M = L + R >> 1;
        return T(Query(st[node].lc, L, M, ql, min(qr, M)),
                    Query(st[node].rc, M + 1, R, max(M + 1, ql), qr));
    }

    void Update(int node, int L, int R, int ul, int ur, const U& val) {
        if(st[node].pending) prop(node, L, R);
        if(ur < ul) return;
        if(ul == L and R == ur)
            return st[node].lazy += val, prop(node, L, R);
        int M = L + R >> 1, lc = st[node].lc, rc = st[node].rc;

        lc = create(lc); st[node].lc = lc;
        Update(lc, L, M, ul, min(ur, M), val);

        rc = create(rc); st[node].rc = rc;
        Update(rc, M + 1, R, max(M + 1, ul), ur, val);

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

    // [l, r] inclusive; in_place = true -> replace version[ver] with new root
    // update(ver, in_place, ul, ur, args...) -> update(ver, in_place, ul, ur, Lazy(args...))
    template<class... Args>
    int update(int ver, bool in_place, int ul, int ur, Args&&... args) {
        U val(forward<Args>(args)...);
        if(ver == -1) ver = version_cnt - 1;
        if(!in_place)
            version.push_back(create(version[ver])), ver = version_cnt++;
        Update(version[ver], ONE, N - !ONE, ul, ur, val);
        return ver;
    }

    template<class... Args>
    int update_point(int ver, bool in_place, int pos, Args&&... args) {
        return update(ver, in_place, pos, pos, forward<Args>(args)...);
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
    Blog:
    Hello world:
    More problems:
*/
