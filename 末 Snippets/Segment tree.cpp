template<class T>
struct Segtree {
    int N; vector<T> st;
    Segtree(int N): N(N) {
        int SZ = 1; for(SZ = 1; SZ < N; SZ <<= 1);
        st.resize(2*SZ+2);
    }
    template<class Iter> Segtree(Iter beg, Iter end): N(end-beg) {
        int SZ = 1; for(SZ = 1; SZ < N; SZ <<= 1);
        st.resize(2*SZ+2); build(1, 1, N, beg, end);
    }
    
    template<class Iter> void build(int node, int L, int R, Iter beg, Iter end) {
        if(L == R) return st[node].set(*beg);
        int M = L+R>>1;
        build(node*2, L, M, beg, beg+(M-L)); build(node*2+1, M+1, R, beg+(M-L+1), end);
        st[node] = T(st[node*2], st[node*2+1]);
    }

    T Query(int node, int L, int R, int i, int j) {
        if(i > R or j < L) return T();
        if(i <= L and j >= R) return st[node];
        int M = L+R>>1;
        return T(Query(node*2, L, M, i, j), Query(node*2+1, M+1, R, i, j));
    } 

    void Update(int node, int L, int R, int pos, int val) {
        if(L == R) return st[node].upd(val);
        int M = L+R>>1;
        pos <= M? Update(node*2, L, M, pos, val) : Update(node*2+1, M+1, R, pos, val);
        st[node] = T(st[node*2], st[node*2+1]);
    }

    auto query(int pos) { return Query(1, 1, N, pos, pos); }
    auto query(int l, int r) { return Query(1, 1, N, l, r); }
    void update(int pos, int val) { Update(1, 1, N, pos, val); }
};

struct Node {
    int val;
    Node(int val = 0) : val(val) {}    
    Node(const Node& l, const Node& r)
        : val(l.val + r.val) {}
    void set(int init) { val = init; }
    void upd(int delta) { val += delta; }
};

/*
int32_t main() {
    vector<int> a{1, 2, 3, 4, 5, 6};
    Segtree<Node> st(a.begin(), a.end());

    int N = 1e6;
    Segtree<Node> st2(N);
}
*/
