/**
 🍪 thew6rst
 🍪 10.02.2021 11:41:10
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
    int i, n; int64_t cur = 0, ans = -DESPACITO;
    cin >> n;
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        cur += x;
        ans = max(ans, cur);
        if(cur < 0) cur = 0;
    } cout << ans;
} // ~W 