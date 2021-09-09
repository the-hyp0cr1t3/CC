/* Eulerian Circuit (directed) */
// Hierholzer’s Algorithm

/*
    CPH:
        https://cses.fi/book/book.pdf#page=183
    Hello world:
        https://cses.fi/problemset/task/1693
*/

vector<int> indeg(n), outdeg(n);
vector<vector<int>> g(n);
for(i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    outdeg[--u]++; indeg[--v]++;
    g[u].push_back(v);
}

bool bad = false;
for(i = 1; i < n-1; i++)
    bad |= outdeg[i] ^ indeg[i];

bad |= outdeg[0]-indeg[0] ^ 1;
bad |= indeg[n-1]-outdeg[n-1] ^ 1;

if(bad)
    // IMPOSSIBLE

vector<int> tour;
tour.reserve(m+1);
Y([&](auto dfs, int v) -> void {
    while(outdeg[v]-- > 0)
        dfs(g[v][outdeg[v]]);
    tour.push_back(v);
})(0);

for(i = 0; i < n; i++)
    if(outdeg[i] > 0)
        // IMPOSSIBLE

reverse(tour.begin(), tour.end());
