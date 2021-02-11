/**
 🍪 thew6rst
 🍪 10.02.2021 12:41:50
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
    int i, x, n;
    cin >> x >> n;
    multiset<int, greater<int>> diffs{0, x};
    set<int> points{0, x};
 
    for(i = 0; i < n; i++) {
        int y; cin >> y;
        auto it = points.lower_bound(y);
        if(*it != y) {
            auto it2 = prev(it);
            int a = y - *it2, b = *it - y;
            diffs.erase(diffs.find(a + b));
            diffs.insert(a); diffs.insert(b);
            points.insert(y);
        } cout << *diffs.begin() << ' ';
    }
} // ~W 