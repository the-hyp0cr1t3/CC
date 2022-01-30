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
    void split(treap_node *t, int sz, treap_node* &l, treap_node* &r) {
        if(!t) l = r = nullptr;
        else if(sz <= (t->l? t->l->sz : 0))
            split(t->l, sz, l, t->l), r = t, t->pull();
        else
            split(t->r, sz - (t->l? t->l->sz : 0) - 1, t->r, r), l = t, t->pull();
    }

    void meld(treap_node* &t, treap_node *l, treap_node *r) {
        if(!l or !r) t = l? l : r;
        else if(l->prio > r->prio)
            meld(l->r, l->r, r), t = l, t->pull();
        else
            meld(r->l, l, r->l), t = r, t->pull();
    }

    void insert(treap_node* &t, int sz, treap_node *nd) {
        if(!t) t = nd;
        else if(nd->prio > t->prio)
            split(t, sz, nd->l, nd->r), t = nd;
        else {
            int lsz = t->l? t->l->sz : 0;
            if(sz <= lsz)
                insert(t->l, sz, nd);
            else
                insert(t->r, sz - lsz - 1, nd);
        }
        t->pull();
    }

    void erase(treap_node* &t, int sz) {
        if(!t) return;
        int lsz = t->l? t->l->sz : 0;
        if(sz == lsz)
            meld(t, t->l, t->r);
        else if(sz < lsz)
            erase(t->l, sz);
        else
            erase(t->r, sz - lsz - 1);
        if(t) t->pull();
    }

    void inorder(treap_node *t, vector<treap_node*>& res) {
        if(!t) return;
        inorder(t->l, res);
        res.push_back(t);
        inorder(t->r, res);
    }

    vector<treap_node*> to_vector() {
        if(!root) return {};
        vector<treap_node*> res;
        res.reserve(root->sz);
        inorder(root, res);
        return res;
    }

} // namepsace Treap