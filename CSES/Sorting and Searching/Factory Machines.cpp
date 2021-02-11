/**
 🍪 thew6rst
 🍪 11.02.2021 11:55:36
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
 
const int64_t DESPACITO = 1.05e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n; int64_t k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for(auto& x: a) cin >> x;
 
    auto check = [&a, k](int64_t t) {
        int64_t res = 0;
        for(auto& x: a) {
            res += t / x;
            if(res >= k) return true;
        }
        return res >= k;
    };
 
    int64_t lo = 1, hi = DESPACITO;
    while(lo <= hi) {
        int64_t mid = lo + hi >> 1;
        if(check(mid)) hi = mid - 1;
        else lo = mid + 1;
    } cout << lo;
} // ~W 