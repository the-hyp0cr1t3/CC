/**
 🍪 thew6rst
 🍪 11.02.2021 11:36:14
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
    int i = 0, n, cnt = 0;
    cin >> n;
    vector<tuple<int, int, int>> events(n);
    for(auto& [x, y, z]: events)
        cin >> x >> y, z = i++;
    sort(all(events));
 
    vector<int> ans(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto& [l, r, idx]: events) {
        if(!pq.empty() and pq.top().first < l) {
            auto [x, y] = pq.top(); pq.pop();
            pq.emplace(r, y);
            ans[idx] = y;
        } else {
            pq.emplace(r, ++cnt);
            ans[idx] = cnt;
        }
    }
 
    cout << cnt << '\n';
    for(auto& x: ans) cout << x << ' ';
} // ~W 