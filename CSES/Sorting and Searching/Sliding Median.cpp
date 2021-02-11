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
 
    auto normalize = [&]() {
        while(sz(small) > k+1>>1) {
            big.insert(*small.begin());
            small.erase(small.begin());
        }
        while(sz(big) > k>>1) {
            small.insert(*big.begin());
            big.erase(big.begin());            
        }
    };
 
    for(i = 0; i < k-1; i++)
        big.insert(a[i]);
 
    for(i = k-1; i < n; i++) {
        if(small.empty() or a[i] > *small.begin())
            big.insert(a[i]);
        else small.insert(a[i]);
        normalize();
        cout << *small.begin() << " \n"[i == n-1];
        if(a[i-k+1] > *small.begin())
            big.erase(big.find(a[i-k+1]));
        else small.erase(small.find(a[i-k+1]));
    }
} // ~W 