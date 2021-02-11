/**
 🍪 the_hyp0cr1t3
 🍪 03.02.2021 00:56:58
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
    int i, j, n, x, ans = 0;
    cin >> n >> x;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    sort(all(a));
    for(i = 0, j = n-1; i < j; j--) {
        if(a[i] + a[j] <= x) i++;
        ans++;
    } if(i == j) ans++;
 
    cout << ans;
} // ~W 