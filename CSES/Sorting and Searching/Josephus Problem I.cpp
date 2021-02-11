/**
 🍪 thew6rst
 🍪 10.02.2021 13:21:34
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
    int i, n, k = 1, pos = 0;
    cin >> n;
    ordered_set<int> os;
    for(i = 1; i <= n; i++)
        os.insert(i);
    do {
        pos = (pos + k) % n;
        auto it = os.fbo(pos);
        cout << *it << " \n"[i == n];
        os.erase(it);
    } while(--n);
} // ~W 