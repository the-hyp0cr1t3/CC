/* Floyd-Warshall's all pair shortest paths */

/*
    https://github.com/the-hyp0cr1t3/CC/blob/master/Beginner%20Topics/%5BS5%5D%20Do%20you%20understand%20the%20graphity%20of%20this%20situation/%5BEP%202%5D%20Shortest%20paths/%5BPt%203%5D%20Floyd-Warshall.md
*/

auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

vector d(n, vector<int>(n, INF)), path(n, vector<int>(n, -1));
for(auto [u, v, w]: edges)
    d[u][v] = w, path[u][v] = v;
// d[i][i] = 0;

for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(chmin(d[i][j], d[i][k] + d[k][j]))
                path[i][j] = path[i][k];

vector<int> ans{ u };
while(u ^ v) {
    u = path[u][v];
    ans.push_back(u);
}