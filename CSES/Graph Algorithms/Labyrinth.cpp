/**
 🍪 the_hyp0cr1t3
 🍪 17.05.2021 22:03:26
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

const array dx{1, 0, -1, 0};
const array dy{0, 1, 0, -1};
const string dir = "ULDR";

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, m, stx, sty, ex, ey;
    cin >> n >> m;
    vector<string> a(n);
    for(auto& x: a) cin >> x;

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(a[i][j] == 'A')
                stx = i, sty = j;
            else if(a[i][j] == 'B')
                ex = i, ey = j;


    auto valid = [&](int x, int y) {
        return 0 <= x and x < n and 0 <= y and y < m and a[x][y] != '#';
    };

    vector<vector<int>> d(n, vector<int>(m, -1));
    vector<vector<int>> p(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    d[stx][sty] = 0; q.emplace(stx, sty);

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z];
            int ny = y + dy[z];
            if(valid(nx, ny) and d[nx][ny] == -1) {
                d[nx][ny] = d[x][y] + 1;
                p[nx][ny] = z + 2 & 3;
                q.emplace(nx, ny);
            }
        }
    }

    if(d[ex][ey] == -1)
        return cout << "NO" << '\n', 0;

    string ans;
    while(ex != stx or ey != sty) {
        ans += dir[p[ex][ey]];
        tie(ex, ey) = pair{ex + dx[p[ex][ey]], ey + dy[p[ex][ey]]};
    } reverse(all(ans));

    cout << "YES" << '\n';
    cout << sz(ans) << '\n';
    cout << ans << '\n';
} // ~W