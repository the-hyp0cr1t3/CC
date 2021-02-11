/**
 🍪 the_hyp0cr1t3
 🍪 10.11.2020 11:41:01
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };
 
const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, m = 1, cur = 0;
    cin >> n;
    map<int, int> hsh;
    vector<array<int, 3>> a(n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < 3; j++)
            cin >> a[i][j];
        hsh[a[i][0]]; hsh[a[i][1]];
    }
 
    for(auto& [k, v]: hsh)
        v = m++;
    for(auto& [l, r, c]: a)
        l = hsh[l], r = hsh[r];
    sort(all(a));
 
    vector<int64_t> dp(m+1);
    for(auto& [l, r, c]: a) {
        while(cur < l) chmax(dp[cur+1], dp[cur]), ++cur;
        chmax(dp[r], dp[l-1] + c);
    } while(cur < m) chmax(dp[cur+1], dp[cur]), ++cur;
 
    cout << dp[m] << '\n';
} // ~W