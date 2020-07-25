```c++
int d[N];
vector<int> g[N];

auto bfs = [&] (int root) {
    queue<int> q;
    q.push(root);
    d[root] = 1;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto nxt : g[cur]) {
            if(!d[nxt]) {
                d[nxt] = d[cur] + 1;
                q.push(nxt);
            }
        }
    }
};

```

```c++
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int d[N][N];

auto bfs = [&](pii root) {
    queue<pii> q;
    q.push(root);
    d[root.first][root.second] = 0;
    
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            d[i][j] = INF;

    while(!q.empty()) {
        auto [curx, cury] = q.front();
        q.pop();
    
        for(int i = 0; i < 4; i++) {
            int x = curx + dx[i];
            int y = cury + dy[i];
    
            if(d[curx][cury] + 1 < d[x][y]) {
                d[x][y] = d[curx][cury] + 1;
                q.push({x, y});
            }
        }
    }
};

```