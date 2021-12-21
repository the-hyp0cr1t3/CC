/**
 🍪 the_hyp0cr1t3
 🍪 18.12.2021 20:51:37
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

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

    template<typename A>
    Segtree(const vector<A>& a): N(a.size()), st(1) {
        st.reserve((1 << 31 - __builtin_clz(N << 1) + !!(N & N-1)) + 2);
        version.push_back(create()); version_cnt++;
        build(1, ONE, N - !ONE, a);
    }

    template<class... Args>
    Segtree(int n, Args&&... args): Segtree(vector<T>(n, T(forward<Args>(args)...))) {}

    int copy(int ver) {
        version.push_back(create(version[ver]));
        return version_cnt++;
    }

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
    // using L = int64_t;
    using L = struct Lazy {
        V lzy;
        Lazy(V lzy = 0): lzy(lzy) {}
        operator V() const { return lzy; }
        void operator+=(const Lazy& rhs) { lzy += rhs.lzy; }
    };

    int lc{-1}, rc{-1};
    bool pending{false};
    V val; L lazy{};
    Node(V val = 0): val(val) {}
    Node(const Node& l, const Node& r)
        : val(l.val + r.val) {}
    void apply_lazy(int len) { val += lazy * len; }
    operator V() const { return val; }
};

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif

    vector<int> a{1, 1, 2, 3, 5};

    ps(a);
    Segtree<Node> seg(a);
    seg.update_range(-1, false, 2, 4, 1);

    for(int i = 1; i <= 5; i++) {
        auto x = seg.query(-1, i);
        tr(x);
        ps(); ps();
    }
    // ps(seg.query(-1, 2));
    // ps(seg.query(-1, 2));
    // ps(seg.query(-1, 2));

    // Node x(5);
    // x.lc = 3, x.rc = 4;

} // ~W