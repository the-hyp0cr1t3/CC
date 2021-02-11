/**
 🍪 thew6rst
 🍪 11.02.2021 16:25:43
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
    int i, j, n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
 
    set<tuple<int, int, int>> s;
    for(i = 0; i < n; i++)
        for(j = 0; j < i; j++)
            s.emplace(a[i] + a[j], j+1, i+1);
 
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++)
            s.erase({a[i] + a[j], i+1, j+1});
        for(j = 0; j < i; j++) {
            auto it = s.lower_bound({k-a[i]-a[j], -1, -1});
            if(it != s.end() and get<0>(*it) == k-a[i]-a[j]) {
                cout << j+1 << ' ' << i+1 << ' ';
                cout << get<1>(*it) << ' ' << get<2>(*it);
                return 0;
            }
        }
    } cout << "IMPOSSIBLE";
} // ~W 