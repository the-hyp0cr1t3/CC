
template<class T>
struct SegTree {
    int N; vector<T> st;
    SegTree(int N): N(N) {
        int SZ = 1; for(SZ = 1; SZ < N; SZ <<= 1);
        st.resize(2*SZ+2);
    }
    template<class Iter> SegTree(Iter beg, Iter end): N(end-beg) {
        int SZ = 1; for(SZ = 1; SZ < N; SZ <<= 1);
        st.resize(2*SZ+2); build(1, 1, N, beg, end);
    }
    
    template<class Iter> void build(int node, int L, int R, Iter beg, Iter end) {
        if(L == R) return st[node] <<= *beg;
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

    void Update(int node, int L, int R, int i, int j, int val) {
        if(i > R or j < L) return;
        if(i <= L and j >= R) return st[node] << val;
        int M = L+R>>1;
        Update(node*2, L, M, i, j, val);
        Update(node*2+1, M+1, R, i, j, val);
        st[node] = T(st[node*2], st[node*2+1]);
    }

    auto query(int pos) { return Query(1, 1, N, pos, pos); }
    auto query(int l, int r) { return Query(1, 1, N, l, r); }
    void update(int pos, int val) { Update(1, 1, N, pos, pos, val); }
    void update(int l, int r, int val) { Update(1, 1, N, l, r, val); }
};

struct Node {
    int val;
    Node(int val = 0) : val(val) {}    
    Node(const Node& l, const Node& r) {
        val = min(l.val, r.val);
    }
    void operator<<=(int init) { val = init; }
    void operator<<(int delta) { val += delta; }
};

/* -------------------------------------------------- */
// With lazy prop

template<class T, class U = int>
struct SegTree {
    int N; vector<T> st; vector<U> lazy; vector<bool> pending;
    SegTree(int N): N(N) {
        int SZ = 1; for(SZ = 1; SZ < N; SZ <<= 1);
        st.resize(2*SZ+2); lazy.resize(2*SZ+2); pending.resize(2*SZ+2);
    }
    template<class Iter> SegTree(Iter beg, Iter end): N(end-beg) {
        int SZ = 1; for(SZ = 1; SZ < N; SZ <<= 1);
        st.resize(2*SZ+2); lazy.resize(2*SZ+2); pending.resize(2*SZ+2);
        build(1, 1, N, beg, end);
    }

    template<class Iter> void build(int node, int L, int R, Iter beg, Iter end) {
        if(L == R) return st[node] <<= *beg;
        int M = L+R>>1;
        build(node*2, L, M, beg, beg+(M-L)); build(node*2+1, M+1, R, beg+(M-L+1), end);
        st[node] = T(st[node*2], st[node*2+1]);
    }
    
    void prop(int node, int L, int R) {
        if(L != R) {
            pending[node*2] = pending[node*2+1] = true;
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node]; 
        }
        st[node] << lazy[node];
        pending[node] = false;
        lazy[node] = U();
    }

    T Query(int node, int L, int R, int i, int j) {
        if(pending[node]) prop(node, L, R);
        if(i > R or j < L) return T();
        if(i <= L and j >= R) return st[node];
        int M = L+R>>1;
        return T(Query(node*2, L, M, i, j), Query(node*2+1, M+1, R, i, j));
    }

    void Update(int node, int L, int R, int i, int j, int val) {
        if(pending[node]) prop(node, L, R);
        if(i > R or j < L) return;
        if(i <= L and j >= R) return lazy[node] += val, prop(node, L, R);
        int M = L+R>>1;
        Update(node*2, L, M, i, j, val);
        Update(node*2+1, M+1, R, i, j, val);
        st[node] = T(st[node*2], st[node*2+1]);
    }

    auto query(int pos) { return Query(1, 1, N, pos, pos); }
    auto query(int l, int r) { return Query(1, 1, N, l, r); }
    void update(int pos, int val) { Update(1, 1, N, pos, pos, val); }
    void update(int l, int r, int val) { Update(1, 1, N, l, r, val); }
};

struct Lazy {
    int val;
    Lazy(int val = 0): val(val) {}    
    void operator+=(const int& rhs) { val = rhs; }
    void operator+=(const Lazy& rhs) { val = rhs.val; }
};

struct Node {
    int val;
    Node(int val = 0): val(val) {}    
    Node(const Node& l, const Node& r) {
        val = max(l.val, r.val);
    }
    void operator<<=(int init) { val = init; }
    void operator<<(const Lazy& lzy) { val += lzy.val; }
};
