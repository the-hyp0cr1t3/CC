/**
 🍪 the_hyp0cr1t3
 🍪 03.02.2021 00:51:35
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
    int i, j, n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(auto& x: a) cin >> x;
    for(auto& x: b) cin >> x;
    sort(all(a)); sort(all(b));
 
    for(i = j = 0; i < n; i++) {
        while(j < m and b[j] < a[i]-k) j++;
        if(j < m and b[j] <= a[i]+k) ans++, j++;
    }
 
    cout << ans;
} // ~W 