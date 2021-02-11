/**
 🍪 thew6rst
 🍪 10.02.2021 16:31:28
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
    int i, n, k, ans = 0;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(auto& [r, l]: a) cin >> l >> r;
    sort(all(a));
 
    multiset<int> have;
    for(i = 0; i < k; i++)
        have.insert(0);
 
    for(auto& [r, l]: a) {
        auto it = have.upper_bound(l);
        if(it != have.begin()) {
            have.erase(--it);
            ans++; have.insert(r);
        }
    } cout << ans;
} // ~W