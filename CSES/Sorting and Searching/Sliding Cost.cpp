/**
 🍪 thew6rst
 🍪 11.02.2021 15:42:39
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
 
    // pitcher pouring (Algorithms live)
    multiset<int, greater<int>> small;
    multiset<int> big;
    int64_t small_sum = 0, big_sum = 0;
 
    auto normalize = [&]() {
        while(sz(small) > k+1>>1) {
            big.insert(*small.begin());
            big_sum += *small.begin();
            small_sum -= *small.begin();
            small.erase(small.begin());
        }
        while(sz(big) > k>>1) {
            small.insert(*big.begin());
            small_sum += *big.begin();
            big_sum -= *big.begin();
            big.erase(big.begin());            
        }
    };
 
    auto add = [&](int x) {
        if(small.empty() or x > *small.begin()) {
            big.insert(x); big_sum += x;
        } else {
            small.insert(x); small_sum += x;
        }
    };
 
    auto remove = [&](int x) {
        if(x > *small.begin()) {
            big.erase(big.find(x)); big_sum -= x;
        } else {
            small.erase(small.find(x)); small_sum -= x;
        }
    };
 
    for(i = 0; i < k-1; i++)
        add(a[i]);
 
    auto calc = [&](int64_t x) {
        return big_sum - x * (k/2) + x * (k+1>>1) - small_sum;
    };
 
    for(i = k-1; i < n; i++) {
        add(a[i]); normalize();
        cout << calc(*small.begin()) << " \n"[i == n-1];
        remove(a[i-k+1]);
    }
} // ~W 