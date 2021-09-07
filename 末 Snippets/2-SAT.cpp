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
*/

int vis[2*N], comp[2*N], assignment[N];
vector<int> g[2*N], rg[2*N], order;

// (p → q) if p is true q is also true
void implies(int p, int q) {
    g[p].push_back(q); rg[q].push_back(p);
}

// (p ∨ q) at least one is true
void Or(int p, int q) {
// (¬p → q) ∧ (¬q → p)
    implies(p^1, q); implies(q^1, p);
}

// (p ⊕ q) exactly one is true
void Xor(int p, int q) {
// (p ∨ q) ∧ (¬p ∨ ¬q)
    Or(p, q); Or(p^1, q^1);
}

// (p ↔ q) both are true or both are not
void Biconditional(int p, int q) {
// (p → q) ∧ (q → p) ≡ (p ⊕ ¬q)
    Xor(p, q^1);
}

void dfs1(int v) {
    vis[v] = 1;
    for(auto& x: g[v])
        if(!vis[x]) dfs1(x);
    order.push_back(v);
}

void dfs2(int v, int k) {
    comp[v] = k;
    for(auto& x: rg[v])
        if(comp[x] == -1) dfs2(x, k);
}

// i is represented by 2*i, ¬i is represented by 2*i+1
bool is_sat(int n) {
    memset(comp, -1, sizeof(comp));
    order.reserve(2*n);
    for(int i = 0; i < 2*n; i++)
        if(!vis[i]) dfs1(i);

    reverse(all(order));
    int sccnt = 0;
    for(auto& v: order)
        if(comp[v] == -1)
            dfs2(v, sccnt++);

    for(int i = 0; i < n; i++) {
        if(comp[i<<1] == comp[i<<1|1]) return false;
        // take topologically later option
        assignment[i] = comp[i<<1] > comp[i<<1|1];
    } return true;
}


// -----------------------------------------------------------------------------------------------
/* v2 */

vector<int> comp(n << 1, -1), order, assignment(n);
vector<vector<int>> g(n << 1), rg(n << 1);

auto implies = [&](int p, int q) { g[p].pb(q); rg[q].pb(p); };              // p → q
auto add_or = [&](int p, int q) { implies(p ^ 1, q); implies(q ^ 1, p); };  // p ∨ q ≡ (¬p → q) ∧ (¬q → p)
auto add_xor = [&](int p, int q) { add_or(p, q); add_or(p ^ 1, q ^ 1); };   // p ⊕ q ≡ (p ∨ q) ∧ (¬p ∨ ¬q)
auto add_bicond = [&](int p, int q) { add_xor(p, q ^ 1); };                 // p ↔ q ≡ (p → q) ∧ (q → p) ≡ (p ⊕ ¬q)

auto dfs = Y([&](auto dfs, int v, int k, const auto& gr) -> void {
    comp[v] = k;
    for(auto& x: gr[v])
        if(comp[x] == -1) dfs(x, k, gr);
    if(k == -2) order.pb(v);
});

// add edges here

order.reserve(n << 1);
for(i = 0; i < n << 1; i++)
    if(comp[i] == -1) dfs(i, -2, g);

reverse(all(order));
comp.assign(n << 1, -1);

int _ = 0;
for(auto& v: order)
    if(comp[v] == -1)
        dfs(v, _++, rg);

bool bad = false;
for(i = 0; i < n; i++) {
    if(comp[i << 1] == comp[i << 1 | 1]) bad = true;
    assignment[i] = comp[i << 1] > comp[i << 1 | 1];
}