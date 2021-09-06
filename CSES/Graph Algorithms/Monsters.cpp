/**
 🍪 the_hyp0cr1t3
 🍪 17.05.2021 23:22:20
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
    int i, j, n, m, hx, hy;
    cin >> n >> m;
    vector<string> a(n);
    for(auto& x: a) cin >> x;


    auto valid = [&](int x, int y) {
        return 0 <= x and x < n and 0 <= y and y < m and a[x][y] != '#';
    };

    vector<vector<int>> d(n, vector<int>(m, -1));
    vector<vector<int>> p(n, vector<int>(m, -1));
    queue<tuple<int, int, int>> q;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(a[i][j] == 'A')
                hx = i, hy = j;
            if(a[i][j] == 'M') {
                q.emplace(i, j, 0);
                d[i][j] = 0;
            }
        }
    }
    q.emplace(hx, hy, 1); d[hx][hy] = 1;

    while(!q.empty()) {
        auto [curx, cury, col] = q.front(); q.pop();
        for(int z = 0; z < 4; z++) {
            int nx = curx + dx[z];
            int ny = cury + dy[z];
            if(valid(nx, ny) and d[nx][ny] == -1) {
                d[nx][ny] = col;
                p[nx][ny] = z + 2 & 3;
                q.emplace(nx, ny, col);
            }
        }
    }

    auto Try = [&](int x, int y) {
        if(d[x][y] == 1) {
            string ans;
            while(x != hx or y != hy) {
                ans += dir[p[x][y]];
                tie(x, y) = pair{x + dx[p[x][y]], y + dy[p[x][y]]};
            } reverse(all(ans));
            cout << "YES" << '\n' << sz(ans) << '\n' << ans << '\n';
            exit(0);
        }
    };

    for(i = 0; i < n; i++)
        Try(i, 0), Try(i, m-1);
    for(j = 0; j < m; j++)
        Try(0, j), Try(n-1, j);

    cout << "NO" << '\n';
} // ~W