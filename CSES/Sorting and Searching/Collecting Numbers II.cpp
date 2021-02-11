/**
 🍪 thew6rst
 🍪 10.02.2021 11:59:45
**/
#ifdef W
    #include "k_II.h"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())
 
const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m, ans = 0;
    cin >> n >> m;
    vector<int> pos(n+2, INF), a(n+2);
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
 
    for(i = 1; i <= n; i++)
        ans += pos[i] < pos[i-1];
 
    auto upd = [&](int x, int delta) {
        ans += pos[x] < pos[x-1]? delta : 0;
        ans += pos[x+1] < pos[x]? delta : 0;
    };
 
    while(m--) {
        int x, y; cin >> x >> y;
        upd(a[x], -1); upd(a[y], -1);
        swap(a[x], a[y]); pos[a[x]] = x; pos[a[y]] = y;
        upd(a[x], +1); upd(a[y], +1);
        if(abs(a[x]-a[y]) == 1) {
            int p = min(a[x], a[y]), q = max(a[x], a[y]);
            ans += pos[p] < pos[q]? +1 : -1;
        }
        cout << ans << '\n';
    }
} // ~W 