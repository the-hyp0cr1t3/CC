/**
 🍪 thew6rst
 🍪 10.02.2021 15:52:45
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
    int i, n; int64_t x, ans = 0, cur = 0;
    cin >> n >> x;
    map<int64_t, int> pref;
    pref[0] = 1;
 
    for(i = 0; i < n; i++) {
        int64_t y; cin >> y;
        cur += y;
        ans += pref[cur-x];
        pref[cur]++;
    } cout << ans;
} // ~W 