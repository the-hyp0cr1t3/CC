/* Treap */

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
        https://www.spoj.com/problems/ADACROP/
            http://p.ip.fi/z2n1
        https://codeforces.com/gym/102787/problem/B
            http://p.ip.fi/66Nm
        https://codeforces.com/gym/102787/problem/C
            http://p.ip.fi/6btN
*/

namespace Treap {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    struct treap_node {
        int sz{1};
        mt19937::result_type prio{rng()};
        treap_node *l{nullptr}, *r{nullptr};
        using key_t = int;
        key_t key;

        treap_node(key_t key): key(key) {}

        void pull() {
            sz = 1;
            if(l) sz += l->sz;
            if(r) sz += r->sz;
        }
    };

    inline int size(treap_node *t) {
        return t? t->sz : 0;
    }

    void heapify(treap_node *t) {
        if(!t) return;
        treap_node *mx = t;
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
    treap_node *build(const auto& a, int l, int r) {
        if(r <= l) return nullptr;
        int mid = l + r >> 1;
        treap_node *t = new treap_node(a[mid]);
        t->l = build(a, l, mid);
        t->r = build(a, mid + 1, r);
        t->pull();
        return heapify(t), t;
    }

    // l has subtree size sz
    void split_by_sz(treap_node *t, int sz, treap_node* &l, treap_node* &r) {
        if(!t) l = r = nullptr;
        else if(sz <= size(t->l))
            split_by_sz(t->l, sz, l, t->l), r = t, t->pull();
        else
            split_by_sz(t->r, sz - size(t->l) - 1, t->r, r), l = t, t->pull();
    }

    // r starts with key
    void split_by_key(treap_node *t, treap_node::key_t key, treap_node* &l, treap_node* &r) {
        if(!t) return l = r = nullptr, void();
        if(key <= t->key)
            split_by_key(t->l, key, l, t->l), r = t;
        else
            split_by_key(t->r, key, t->r, r), l = t;
        t->pull();
    }

    void meld(treap_node* &t, treap_node *l, treap_node *r) {
        if(!l or !r) t = l? l : r;
        else if(l->prio > r->prio)
            meld(l->r, l->r, r), t = l, t->pull();
        else
            meld(r->l, l, r->l), t = r, t->pull();
    }

    // pos(i.e. sz) -> 0-based
    void insert_at_pos(treap_node* &t, int sz, treap_node *nd) {
        if(!t) t = nd;
        else if(nd->prio > t->prio)
            split_by_sz(t, sz, nd->l, nd->r), t = nd;
        else {
            if(sz <= size(t->l))
                insert_at_pos(t->l, sz, nd);
            else
                insert_at_pos(t->r, sz - size(t->l) - 1, nd);
        }
        t->pull();
    }

    // returns pos inserted (0-based)
    int insert_key(treap_node* &t, treap_node *nd) {
        int res = 0;
        if(!t) t = nd;
        else if(nd->prio > t->prio)
            split_by_key(t, nd->key, nd->l, nd->r), t = nd, res += size(t->l);
        else {
            if(nd->key > t->key)
                res += 1 + size(t->l);
            res += insert_key(nd->key < t->key? t->l : t->r, nd);
        }
        t->pull();
        return res;
    }

    // pos(i.e. sz) -> 0-based
    void erase_at_pos(treap_node* &t, int sz) {
        if(!t) return;
        if(sz == size(t->l))
            meld(t, t->l, t->r);
        else if(sz < size(t->l))
            erase_at_pos(t->l, sz);
        else
            erase_at_pos(t->r, sz - size(t->l) - 1);
        if(t) t->pull();
    }

    // returns pos erased (0-based)
    int erase_key(treap_node* &t, treap_node::key_t key) {
        if(!t) return 0;
        int res = 0;
        if(key == t->key)
            res += size(t->l), meld(t, t->l, t->r);
        else {
            if(key > t->key)
                res += 1 + size(t->l);
           res += erase_key(key < t->key ? t->l : t->r, key);
        }
        if(t) t->pull();
        return res;
    }

    int order_of_key(treap_node *t, treap_node::key_t key) {
        if(!t) return 0;
        int res = 0;
        if(key == t->key)
            res += size(t->l);
        else {
            if(key > t->key)
                res += 1 + size(t->l);
           res += order_of_key(key < t->key ? t->l : t->r, key);
        }
        return res;
    }

    void inorder(treap_node *t, vector<treap_node*>& res) {
        if(!t) return;
        inorder(t->l, res);
        res.push_back(t);
        inorder(t->r, res);
    }

    vector<treap_node*> to_vector(treap_node *t) {
        if(!t) return {};
        vector<treap_node*> res;
        res.reserve(t->sz);
        inorder(t, res);
        return res;
    }

} // namepsace Treap