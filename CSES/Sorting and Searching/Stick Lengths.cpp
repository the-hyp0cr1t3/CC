/**
 🍪 thew6rst
 🍪 10.02.2021 11:43:54
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
const int N = 1e9;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
 
    auto check = [&a](int k) {
        int64_t res = 0;
        for(auto& x: a)
            res += abs(x-k);
        return res;
    };
 
    int lo = 1, hi = N;
    while(hi - lo > 3) {
        int mid = lo + hi >> 1;
        if(check(mid) >= check(mid+1))
            lo = mid;
        else hi = mid + 1;
    }
 
    cout << min({check(lo), check(lo+1), check(lo+2), check(lo+3)});
} // ~W 