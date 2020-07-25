// Inspired by [Ashishgup](https://github.com/Ashishgup1/Competitive-Coding)
struct Data {
    int val;
    Data() : val(0) {}

    void init(int idx) {
        this->val = a[idx-1];
    }

    void merge(const Data& l, const Data& r) {
        this->val = min(l.val, r.val);
    }

    void updateval(int val) {
        this->val = val;
    }

};

struct SegTree {
    int N;
    vector<Data> st;

    void build(int node, int L, int R) {
        if(L == R) {
            st[node].init(L);
            return;
        }
        int M = (L+R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        st[node].merge(st[node*2], st[node*2+1]);
    }

    SegTree(int n) : N(n) {
        st.rsz(4*n + 5);
    }

    Data Query(int node, int L, int R, int i, int j) {
        if(i > R or j < L)
            return Data();
        if(i <= L and j >= R)
            return st[node];
        int M = (L + R)/2;
        Data left = Query(node*2, L, M, i, j);
        Data right = Query(node*2 + 1, M + 1, R, i, j);
        Data cur; cur.merge(left, right);
        return cur;
    } 

    void Update(int node, int L, int R, int i, int j, int val) {
        if(i > R or j < L)
            return;
        if(i <= L and j >= R) {
            st[node].updateval(val);
            return;
        }
        int M = (L + R)/2;
        Update(node*2, L, M, i, j, val);
        Update(node*2 + 1, M + 1, R, i, j, val);
        st[node].merge(st[node*2], st[node*2 + 1]);
    }

    Data query(int pos) {
        return Query(1, 1, N, pos, pos);
    }

    Data query(int l, int r) {
        return Query(1, 1, N, l, r);
    }

    void update(int pos, int val) {
        Update(1, 1, N, pos, pos, val);
    }

    void update(int l, int r, int val) {
        Update(1, 1, N, l, r, val);
    }

};

/* -------------------------------------------------- */
// With lazy prop
struct Data {
    int val;
    Data() : val(0) {}

    void init(int idx) {
        this->val = a[idx-1];
    }

    void merge(const Data& l, const Data& r) {
        this->val = min(l.val, r.val);
    }

    void lazymerge(int delta) {
        this->val += delta;
    }
};

struct SegTree {
    int N;
    vector<Data> st;
    vector<bool> cLazy;
    vector<int> lazy;

    void build(int node, int L, int R) {
        if(L == R) {
            st[node].init(L);
            return;
        }
        int M = (L+R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        st[node].merge(st[node*2], st[node*2+1]);
    }

    SegTree(int n) : N(n) {
        st.rsz(4*n + 5);
        cLazy.assign(4*n + 5, false);
        lazy.assign(4*n + 5, 0);
    }
    
    void propagate(int node, int L, int R) {
        if(L != R) {
            cLazy[node*2] = 1;
            cLazy[node*2 + 1] = 1;
            lazy[node*2] += lazy[node];
            lazy[node*2 + 1] += lazy[node]; 
        }
        st[node].lazymerge(lazy[node]);
        cLazy[node] = 0;
        lazy[node] = 0;
    }

    Data Query(int node, int L, int R, int i, int j) {
        if(cLazy[node])
            propagate(node, L, R);
        if(i > R or j < L)
            return Data();
        if(i <= L and j >= R)
            return st[node];
        int M = (L + R)/2;
        Data left = Query(node*2, L, M, i, j);
        Data right = Query(node*2 + 1, M + 1, R, i, j);
        Data cur; cur.merge(left, right);
        return cur;
    } 

    void Update(int node, int L, int R, int i, int j, int val) {
        if(cLazy[node])
            propagate(node, L, R);
        if(i > R or j < L)
            return;
        if(i <= L and j >= R) {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        Update(node*2, L, M, i, j, val);
        Update(node*2 + 1, M + 1, R, i, j, val);
        st[node].merge(st[node*2], st[node*2 + 1]);
    }

    Data query(int pos) {
        return Query(1, 1, N, pos, pos);
    }

    Data query(int l, int r) {
        return Query(1, 1, N, l, r);
    }

    void update(int pos, int val) {
        Update(1, 1, N, pos, pos, val);
    }

    void update(int l, int r, int val) {
        Update(1, 1, N, l, r, val);
    }

};

