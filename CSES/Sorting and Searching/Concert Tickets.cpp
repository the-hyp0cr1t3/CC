/**
 🍪 the_hyp0cr1t3
 🍪 03.02.2021 01:26:32
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
    int i, n, m;
    cin >> n >> m;
    multiset<int> s;
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(-x);
    }
 
    while(m--) {
        int x; cin >> x;
        auto it = s.lower_bound(-x);
        if(it == s.end())
            cout << -1 << '\n';
        else {
            cout << -*it << '\n';
            s.erase(it);
        }
    }
} // ~W 