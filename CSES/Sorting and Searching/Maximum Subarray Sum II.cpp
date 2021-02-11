/**
 🍪 thew6rst
 🍪 11.02.2021 15:31:06
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
int a[N];
int64_t pref[N];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, x, y; int64_t ans = -DESPACITO;
    cin >> n >> x >> y;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
 
    multiset<int64_t> ms;
    for(i = 1; i <= n; i++) {
        if(i-x >= 0) ms.insert(pref[i-x]);
        if(!ms.empty()) ans = max(ans, pref[i] - *ms.begin());
        if(i-y >= 0) ms.erase(ms.find(pref[i-y]));
    }
 
    cout << ans;
} // ~W 