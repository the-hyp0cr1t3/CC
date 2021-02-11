/**
 🍪 thew6rst
 🍪 10.02.2021 11:32:16
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
    int i = 0, j, n, X;
    cin >> n >> X;
    vector<pair<int, int>> a(n);
    for(auto& [x, y]: a) cin >> x, y = ++i;
    sort(all(a));
    for(i = 0, j = n-1; i < j; i++) {
        while(i < j and a[i].first + a[j].first > X) j--;
        if(i < j and a[i].first + a[j].first == X)
            return cout << a[i].second << ' ' << a[j].second, 0;
    } cout << "IMPOSSIBLE";
} // ~W 