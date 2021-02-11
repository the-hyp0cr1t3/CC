/**
 🍪 thew6rst
 🍪 11.02.2021 12:10:12
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
    int i, n; int64_t t = 0, ans = 0;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(auto& [x, y]: a) cin >> x >> y;
    sort(all(a));
    for(auto& [x, y]: a) {
        t += x; ans += 1LL * y - t;
    } cout << ans;
} // ~W 