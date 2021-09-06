/**
 🍪 the_hyp0cr1t3
 🍪 17.05.2021 21:55:07
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

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const array dx{1, 0, -1, 0};
const array dy{0, 1, 0, -1};

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, m, ans = 0;
    cin >> n >> m;
    vector<string> a(n);
    for(auto& x: a) cin >> x;

    auto valid = [&](int x, int y) {
        return 0 <= x and x < n and 0 <= y and y < m and a[x][y] == '.';
    };

    vector<vector<int>> vis(n, vector<int>(m));
    auto dfs = Y([&](auto dfs, int x, int y) -> void {
        vis[x][y] = 1;
        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z];
            int ny = y + dy[z];
            if(valid(nx, ny) and !vis[nx][ny])
                dfs(nx, ny);
        }
    });

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(!vis[i][j] and a[i][j] == '.')
                dfs(i, j), ans++;

    cout << ans << endl;
} // ~W