//Hierholzer’s Algorithm for Euler circuit
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define sz(x) (int)(x).size()
const int N = 1e5 + 5;
vector<int> g[N], circuit;
int n, m;

void makeG() {
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
}

void EulerCycle(int v) {
    stack<int> curpath;
    curpath.push(v);
    int cur = v;
    while(!curpath.empty()) {
        if(sz(g[cur])) {
            int nxt = g[cur].back();
            curpath.push(nxt);
            g[cur].pop_back();
            cur = nxt;
        }
        else {
            cur = curpath.top();
            circuit.push_back(cur+1);
            curpath.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
}

int32_t main() {
    IOS;
    cin >> n >> m;
    circuit.reserve(m+2);
    makeG();
    EulerCycle(0);
    for(auto& x: circuit) 
        cout << x << " ";
    return 0;
}