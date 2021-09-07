/* Breadth First Search */

/*
    https://github.com/the-hyp0cr1t3/CC/blob/master/Beginner%20Topics/%5BS5%5D%20Do%20you%20understand%20the%20graphity%20of%20this%20situation/%5BEP%201%5D%20Graph%20traversal/%5BPt%202%5D%20BFS.md
*/

vector<vector<int>> g(n);       // adjacency list

auto bfs = [&](int root) {
    queue<int> q; q.push(root);
    vector<int> d(n, -1); d[root] = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(auto nxt : g[cur]) {
            if(d[nxt] == -1) {
                d[nxt] = d[cur] + 1;
                q.push(nxt);
            }
        }
    } return d;
};

// ---------------------------------------------------------
/* BFS 2D */

const array dx{1, 0, -1, 0};
const array dy{0, 1, 0, -1};

auto valid = [&](int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < m and a[x][y] != '#';
};

auto bfs = [&](int stx, int sty) {
    queue<pair<int, int>> q;
    vector<vector<int>> d(n, vector<int>(m, -1));
    q.emplace(stx, sty); d[stx][sty] = 0;
    while(!q.empty()) {
        auto [curx, cury] = q.front(); q.pop();
        for(int z = 0; z < 4; z++) {
            int nx = curx + dx[z];
            int ny = cury + dy[z];
            if(valid(nx, ny) and d[nx][ny] == -1) {
                d[nx][ny] = d[curx][cury] + 1;
                q.emplace(nx, ny);
            }
        }
    } return d;
};