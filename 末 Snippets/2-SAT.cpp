/* 2-Satisfiability or 2-SAT */

/*
    Blog:
        https://codeforces.com/blog/entry/92977
    Algorithms Live:
        https://www.youtube.com/watch?v=0nNYy3rltgA
    CP algorithms:
        https://cp-algorithms.com/graph/2SAT.html
    Hello world:
        https://cses.fi/problemset/task/1684
    More problems:
        https://codeforces.com/contest/1475/problem/F
            https://codeforces.com/contest/1475/submission/105420153
        https://codeforces.com/contest/776/problem/D
            https://codeforces.com/contest/776/submission/94490003
        https://codeforces.com/contest/1615/problem/D
            https://codeforces.com/contest/1615/submission/142375358 (updated)
*/

// 0-indexed, (i, ¬i) represented by (i, i + n)
class TwoSAT {
    int N;
    vector<int> comp, order;
    vector<vector<int>> g, rg;

    int complement(int i) { return i < N? i + N : i - N; }

    void dfs(int v, int k, const vector<vector<int>>& gr) {
        comp[v] = k;
        for(auto& x: gr[v])
            if(comp[x] == -1) dfs(x, k, gr);
        if(k == -2) order.push_back(v);
    };

public:

    TwoSAT(int n): N(n), comp(n << 1, -1), g(n << 1), rg(n << 1) {}

    // p, q ∈ [0, 2n)
    void implies(int p, int q) { g[p].push_back(q); rg[q].push_back(p); };                  // p → q
    void add_truth(int p) { implies(complement(p), p); }                                    // p ≡ ¬p → p
    void add_or (int p, int q) { implies(complement(p), q); implies(complement(q), p); };   // p ∨ q ≡ (¬p → q) ∧ (¬q → p)
    // p, q ∈ [0, n) sufficient
    void add_xor(int p, int q) { add_or(p, q); add_or(complement(p), complement(q)); };     // p ⊕ q ≡ (p ∨ q) ∧ (¬p ∨ ¬q)
    void add_bicond(int p, int q) { add_xor(p, complement(q)); };                           // p ↔ q ≡ (p → q) ∧ (q → p) ≡ (p ⊕ ¬q)

    bool is_sat() {
        order.reserve(N << 1);
        for(int i = 0; i < N << 1; i++)
            if(comp[i] == -1) dfs(i, -2, g);

        reverse(order.begin(), order.end());
        comp.assign(N << 1, -1);

        int _ = 0;
        for(auto& v: order)
            if(comp[v] == -1) dfs(v, _++, rg);

        for(int i = 0; i < N; i++)
            if(comp[i] == comp[i + N]) return false;

        return true;
    }

    vector<int> get_assignment() {
        vector<int> assn(N);
        for(int i = 0; i < N; i++)
            assn[i] = comp[i] > comp[i + N];
        return assn;
    }

};