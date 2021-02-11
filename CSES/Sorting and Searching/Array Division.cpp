/**
 🍪 thew6rst
 🍪 10.02.2021 16:17:31
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
    int i, n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
 
    auto check = [&a, k](int64_t x) {
        int p = 1; int64_t cur = 0;
        for(auto y: a) {
            if(cur + y > x)
                p++, cur = 0;
            cur += y;
        } return p <= k;
    };
 
    int64_t lo = *max_element(all(a)), hi = DESPACITO;
    while(lo <= hi) {
        int64_t mid = lo + hi >> 1;
        if(check(mid)) hi = mid - 1;
        else lo = mid + 1;
    } cout << lo;
} // ~W 