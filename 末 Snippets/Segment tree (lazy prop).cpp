// Read and practice more from [https://codeforces.com/edu/course/2/lesson/5]
// Try [https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/A]

// T = Node, U = Lazy
template<class T, class U = int64_t>
struct Segtree {
    int N; vector<T> st; vector<U> lazy; vector<bool> pending;
    Segtree(int N)
        : N(N), st(this->getmx(N)), lazy(st.size()), pending(st.size()) {}
    template<class Iter> Segtree(Iter beg, Iter end)
        : Segtree(end-beg) { build(1, 1, N, beg, end); }
    int getmx(int x) { int y = 1; for(y=1, x<<=1; y<x; y<<=1); return y+2; }

    template<class Iter>
    void build(int node, int L, int R, Iter beg, Iter end) {
        if(L == R) return st[node].set(*beg);
        int M = L + R >> 1;
        build(node<<1, L, M, beg, beg+(M-L));
        build(node<<1|1, M+1, R, beg+(M-L+1), end);
        st[node] = T(st[node<<1], st[node<<1|1]);
    }
    
    void prop(int node, int L, int R) {
        if(L != R) {
            pending[node<<1] = pending[node<<1|1] = true;
            lazy[node<<1] += lazy[node];        // overload += for custom class U
            lazy[node<<1|1] += lazy[node];
        }
        st[node].upd(lazy[node]);
        pending[node] = false; lazy[node] = U();
    }

    T Query(int node, int L, int R, int i, int j) {
        if(pending[node]) prop(node, L, R);
        if(i > R or j < L) return T();
        if(i <= L and j >= R) return st[node];
        int M = L + R >> 1;
        return T(Query(node<<1, L, M, i, j), 
                    Query(node<<1|1, M+1, R, i, j));
    } 

    void Update(int node, int L, int R, int i, int j, int64_t val) {
        if(pending[node]) prop(node, L, R);
        if(i > R or j < L) return;
        if(i <= L and j >= R) return lazy[node] += val, prop(node, L, R);
        int M = L + R >> 1;
        Update(node<<1, L, M, i, j, val);
        Update(node<<1|1, M+1, R, i, j, val);
        st[node] = T(st[node<<1], st[node<<1|1]);
    }

    // helper/wrapper funcs; 1-based indexing; (l, r) inclusive of both ends.
    auto query(int pos) { return Query(1, 1, N, pos, pos); }
    auto query(int l, int r) { return Query(1, 1, N, l, r); }
    void update(int pos, int64_t val) { Update(1, 1, N, pos, pos, val); }
    void update(int l, int r, int64_t val) { Update(1, 1, N, l, r, val); }
};

struct Lazy {
    int64_t lzy{0};
    operator int64_t() const { return lzy; }        // st[node].upd(int)
    void operator+=(int64_t rhs) { lzy += rhs; }    // lazy[node<<1] += lazy[node]
};

struct Node {
    int val{0};             // brace initialize all default values
    Node() = default;
    Node(const Node& l, const Node& r)          // merge two nodes
        : val(l.val + r.val) {}
    void set(int init) { val = init; }          // set value during build()
    void upd(int64_t delta) { val += delta; }   // update value
};

/*
int32_t main() {
    // Note: construct only using containers with random access iterators
    // (or C style arrays) since Segtree::build() assumes so.
    vector<int> a{1, 2, 3, 4, 5, 6};
    Segtree<Node, Lazy> st(a.begin(), a.end());

    int arr[] = {3, 4, 5, 6, 7};
    Segtree<Node, Lazy> st2(arr, arr+5);
    
    int N = 1e6;
    Segtree<Node> st3(N);
}
*/
