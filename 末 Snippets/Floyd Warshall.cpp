int d[N][N];
vector<int> ans;

for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
        d[i][j] = INF;
        p[i][j] = -1;
    }
    d[i][i] = 0;
    p[i][i] = 0;
}

for(i = 0; i < m; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    u--, v--;
    d[u][v] = d[v][u] = cost;
    p[u][v] = v;
    p[v][u] = u;
}

void warshall() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(d[i][k]^INF and d[k][j]^INF and (d[i][k]+d[k][j] < d[i][j])) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[i][k];
                }
            }
        }
    }
};

void path(int u, int v) {
    ans.pb(u+1);
    if(u == v) return;
    path(p[u][v], v);    
}

