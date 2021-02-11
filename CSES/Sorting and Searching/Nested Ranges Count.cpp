/**
 🍪 thew6rst
 🍪 10.02.2021 13:41:04
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class key, class value = null_type, class cmp = std::less<key>>
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key    // count of elements strictly smaller than k
#define fbo find_by_order   // iterator to kth element starting from 0
 
const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i = 0, n;
    cin >> n;
 
    vector<array<int, 3>> a(n);
    ordered_set<pair<int, int>> start, end;
    vector<int> inside(n), outside(n);
 
    for(auto& [l, r, idx]: a) {
        cin >> l >> r; idx = i++;
        end.insert({l, idx});
    }
 
    sort(all(a), [](const auto& A, const auto& B) { 
        return A[1] == B[1]? A[0] > B[0] : A[1] < B[1]; 
    });
 
    for(i = 0; i < n; i++) {
        inside[a[i][2]] = sz(start) - start.ook({a[i][0], -1});
        start.insert({a[i][0], a[i][2]});
        end.erase({a[i][0], a[i][2]});
        outside[a[i][2]] = end.ook({a[i][0], INF});
    }
 
    for(i = 0; i < n; i++)
        cout << inside[i] << " \n"[i == n-1];
    for(i = 0; i < n; i++)
        cout << outside[i] << " \n"[i == n-1];
} // ~W 