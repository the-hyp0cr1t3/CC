/* Segment tree with point updates */
// Try [https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A]
// Practice from [https://codeforces.com/edu/course/2/lesson/4]

template<class T>
struct Segtree {
    int N; vector<T> st;
    Segtree(int N)
        : N(N), st(ceil2n(N)) {}
    template<class Iter> Segtree(Iter beg, Iter end)
        : Segtree(end-beg) { build(1, 1, N, beg, end); }
    static int ceil2n(int x) {
        return (1 << 31 - __builtin_clz(x << 1) + !!(x & x-1)) + 2;
    }

    template<class Iter>
    void build(int node, int L, int R, Iter beg, Iter end) {
        if(L == R) return st[node].set(*beg);
        int M = L + R >> 1;
        build(node<<1, L, M, beg, beg+(M-L));
        build(node<<1|1, M+1, R, beg+(M-L+1), end);
        st[node] = T(st[node<<1], st[node<<1|1]);
    }

    T Query(int node, int L, int R, int i, int j) {
        if(i > R or j < L) return T();
        if(i <= L and j >= R) return st[node];
        int M = L + R >> 1;
        return T(Query(node<<1, L, M, i, j), 
                    Query(node<<1|1, M+1, R, i, j));
    } 

    void Update(int node, int L, int R, int pos, int64_t val) {
        if(L == R) return st[node].upd(val);
        int M = L + R >> 1;
        pos <= M? Update(node<<1, L, M, pos, val)
                    : Update(node<<1|1, M+1, R, pos, val);
        st[node] = T(st[node<<1], st[node<<1|1]);
    }

    // helper/wrapper funcs; 1-based indexing; (l, r) inclusive of both ends.
    auto query(int pos) { return Query(1, 1, N, pos, pos); }
    auto query(int l, int r) { return Query(1, 1, N, l, r); }
    void update(int pos, int64_t val) { Update(1, 1, N, pos, val); }
};
// do not edit the above code

// struct Node must be edited accordingly
struct Node {
    int val{0};     // brace initialize all default values
    Node() = default;
    Node(const Node& l, const Node& r)      // merge two nodes
        : val(l.val + r.val) {}
    void set(int init) { val = init; }      // set value during build()
    void upd(int delta) { val += delta; }   // update value
    operator int() const { return val; }
};
/*
int32_t main() {
    // Note: construct only using containers with random access iterators
    // (or C style arrays) since Segtree::build() assumes so.
    vector<int> a{1, 2, 3, 4, 5, 6};
    Segtree<Node> st(a.begin(), a.end());

    int arr[] = {3, 4, 5, 6};
    Segtree<Node> st2(arr, arr+4);
    
    int N = 1e6;
    Segtree<Node> st3(N);
}
*/
