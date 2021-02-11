/**
 🍪 thew6rst
 🍪 11.02.2021 13:37:30
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
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    cout << max(accumulate(all(a), 0LL), 2LL * *max_element(all(a)));
} // ~W 