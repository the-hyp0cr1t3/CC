/**
 🍪 thew6rst
 🍪 10.02.2021 11:29:35
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
    int n, ans = 0, cur = -1;
    cin >> n;
    vector<pair<int, int>> events(n);
    for(auto &[x, y]: events) cin >> y >> x;
    sort(all(events));
    for(auto &[x, y]: events)
        if(y >= cur) ans++, cur = x;
    cout << ans;
} // ~W 