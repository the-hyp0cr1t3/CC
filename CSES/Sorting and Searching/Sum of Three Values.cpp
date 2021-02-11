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
    int i = 0, j, n, k;
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    for(auto& [x, y]: a)
        cin >> x, y = ++i;
    sort(all(a));
    for(i = 0; i < n; i++) {
        for(j = 0; j < i; j++) {
            auto it = lower_bound(a.begin()+i+1, a.end(), array{k-a[i][0]-a[j][0], -1});
            if(it != a.end() and (*it)[0] == k-a[i][0]-a[j][0])
                return cout << a[j][1] << ' ' << a[i][1] << ' ' << (*it)[1], 0;
        }
    } cout << "IMPOSSIBLE";
} // ~W 