/* Treap (with lazy prop) */

/*
    Blog:
        https://codeforces.com/blog/entry/84017
    SecondThread:
        https://www.youtube.com/watch?v=6x0UlIBLRsc
    CP algorithms:
        https://cp-algorithms.com/data_structures/treap.html
    Hello world:
        https://codeforces.com/contest/863/problem/D
    Problems:
        https://codeforces.com/gym/102787

    Examples:
        https://codeforces.com/gym/102787/problem/B
            http://p.ip.fi/rW9o
        https://codeforces.com/gym/102787/problem/C
            http://p.ip.fi/-MjA
*/

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
struct Treap {
    T *root;
    using key_t = T::key_t;

    operator T*() const { return root; }
    explicit Treap(T *t = nullptr): root(t) {}

    Treap(const auto& a): root(build(a, 0, a.size())) {}

    template<class... Args>
    Treap(int N, Args&&... args): Treap(vector<T>(N, T(forward<Args>(args)...))) {}


    void heapify(T *t) {
        if(!t) return;
        T *mx = t;
        if(t->l and t->l->prio > mx->prio)
            mx = t->l;
        if(t->r and t->r->prio > mx->prio)
            mx = t->r;
        if(mx != t) {
            swap(t->prio, mx->prio);
            heapify(mx);
        }
    }

    // [l, r)
    T *build(const auto& a, int l, int r) {
        if(r <= l) return nullptr;
        int mid = l + r >> 1;
        T *t = new T(a[mid]);
        t->l = build(a, l, mid);
        t->r = build(a, mid + 1, r);
        t->pull();
        return heapify(t), t;
    }

    // l has subtree size sz
    static void split_by_sz(T *t, int sz, T* &l, T* &r) {
        if(!t) return l = r = nullptr, void();
        t->prop();
        if(sz <= (t->l? t->l->sz : 0))
            split_by_sz(t->l, sz, l, t->l), r = t;
        else
            split_by_sz(t->r, sz - (t->l? t->l->sz : 0) - 1, t->r, r), l = t;
        t->pull();
    }

    // r starts with key
    static void split_by_key(T *t, key_t key, T* &l, T* &r) {
        if(!t) return l = r = nullptr, void();
        t->prop();
        if(key <= t->key)
            split_by_key(t->l, key, l, t->l), r = t;
        else
            split_by_key(t->r, key, t->r, r), l = t;
        t->pull();
    }

    static void meld(T* &t, T *l, T *r) {
        if(l) l->prop();
        if(r) r->prop();
        if(!l or !r) t = l? l : r;
        else if(l->prio > r->prio)
            meld(l->r, l->r, r), t = l;
        else
            meld(r->l, l, r->l), t = r;
        if(t) t->pull();
    }

    static void insert_at_pos(T* &t, int sz, T *nd) {
        if(!t) t = nd;
        else if(nd->prio > t->prio)
            split_by_sz(t, sz, nd->l, nd->r), t = nd;
        else {
            t->prop();
            int lsz = t->l? t->l->sz : 0;
            if(sz <= lsz)
                insert_at_pos(t->l, sz, nd);
            else
                insert_at_pos(t->r, sz - lsz - 1, nd);
        }
        t->pull();
    }

    static void insert_key(T* &t, T *nd) {
        if(!t) t = nd;
        else if(nd->prio > t->prio)
            split_by_key(t, nd->key, nd->l, nd->r), t = nd;
        else {
            t->prop();
            insert_key(nd->key < t->key? t->l : t->r, nd);
        }
        t->pull();
    }

    static void erase_at_pos(T* &t, int sz) {
        if(!t) return;
        t->prop();
        int lsz = t->l? t->l->sz : 0;
        if(sz == lsz)
            meld(t, t->l, t->r);
        else if(sz < lsz)
            erase_at_pos(t->l, sz);
        else
            erase_at_pos(t->r, sz - lsz - 1);
        if(t) t->pull();
    }

    static void erase_key(T* &t, key_t key) {
        if(!t) return;
        t->prop();
        if(key == t->key)
            meld(t, t->l, t->r);
        else
            erase_key(key < t->key ? t->l : t->r, key);
        if(t) t->pull();
    }

    // 0-based [lpos, rpos)
    void erase_interval(int lpos, int rpos) {
        T *x{nullptr}, *t{root}, *y{nullptr};
        if(rpos < root->sz)
            split_by_sz(root, rpos, t, y);
        if(lpos > 0)
            split_by_sz(t, lpos, x, t);
        meld(root, x, y);
    }

    // pos -> 0-based
    void insert_at_pos(int pos, T *nd) { insert_at_pos(root, pos, nd); }
    void erase_at_pos(int pos) { erase_at_pos(root, pos); }
    void insert_key(key_t key) { insert_key(root, new T(key)); }
    void erase_key(key_t key) { erase_key(root, key); }

    // 0-based [lpos, rpos)
    T query(int lpos, int rpos) {
        T *x{nullptr}, *t{root}, *y{nullptr};
        if(rpos < root->sz)
            split_by_sz(root, rpos, t, y);
        if(lpos > 0)
            split_by_sz(t, lpos, x, t);
        T res = *t;
        meld(t, x, t);
        meld(root, t, y);
        return res;
    }

    // 0-based [lpos, rpos)
    template<class... Args>
    void update(int lpos, int rpos, Args&&... args) {
        T *x{nullptr}, *t{root}, *y{nullptr};
        if(rpos < root->sz)
            split_by_sz(root, rpos, t, y);
        if(lpos > 0)
            split_by_sz(t, lpos, x, t);
        t->update(forward<Args>(args)...);
        meld(t, x, t);
        meld(root, t, y);
    }

    void inorder(T *t, vector<T*>& res) {
        if(!t) return;
        t->prop();
        inorder(t->l, res);
        res.push_back(t);
        inorder(t->r, res);
        t->pull();
    }

    vector<T*> to_vector() {
        if(!root) return {};
        vector<T*> res;
        res.reserve(root->sz);
        inorder(root, res);
        return res;
    }

};

struct treap_node {
    int sz{1};
    mt19937::result_type prio{rng()};
    treap_node *l{nullptr}, *r{nullptr};
    using key_t = int;
    key_t key;

    treap_node(key_t key): key(key) {}

    void prop() {}

    void pull() {
        sz = 1;
        if(l) {
            l->prop();
            sz += l->sz;
        }
        if(r) {
            r->prop();
            sz += r->sz;
        }
    }

    void update() {}
};