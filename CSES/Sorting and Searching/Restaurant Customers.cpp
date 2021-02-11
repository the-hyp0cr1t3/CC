/**
 🍪 the_hyp0cr1t3
 🍪 03.02.2021 01:32:07
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
    int i, n;
    cin >> n;
    vector<pair<int, int>> events;
    events.reserve(2*n);
    for(i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        events.pb(a, 1); events.pb(++b, 0);
    } sort(all(events));
 
    int cur = 0, ans = 0;
    for(auto& [x, o]: events) {
        cur += o? 1 : -1;
        ans = max(ans, cur);
    }
 
    cout << ans;
} // ~W 