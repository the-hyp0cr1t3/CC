/**
 🍪 thew6rst
 🍪 11.02.2021 17:18:28
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

    auto LIS = [&] (const vector<int>& v) {
        vector<int> lis; lis.reserve(n);
        for(int z = 0; z < n; z++) {
            // v[A] <= v[B] for strictly incr, v[A] < v[B] otherwise
            auto it = upper_bound(all(lis), z, [&](const auto& A, const auto& B) { 
                return v[A] <= v[B];
            });
            int idx = int(it - lis.begin());
            if(it == lis.end()) lis.pb(z);
            else lis[idx] = z;
        } return sz(lis);
    };
    
    cout << LIS(a);
} // ~W 