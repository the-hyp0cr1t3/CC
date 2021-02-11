/**
 🍪 the_hyp0cr1t3
 🍪 31.08.2020 10:14:30
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define endl '\n'
#define pb emplace_back
// #define int long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };
 
using ll = long long;
using pii = pair<int, int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
 
const int N = 2e5+5;
int a[N];
 
int32_t main() {
    aylmao
    int i, n, cur = 1; ll ans = 0;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    deque<ll> v;
    for(i = 0; i < n; i++) {
        v.push_back(a[i]);
        while(sz(v) > 2) {
            ll x = v[sz(v)-3];
            ll y = v[sz(v)-2];
            ll z = v[sz(v)-1];
            if(x > y or y < z) break;
            v.pop_back(); v.pop_back(); v.pop_back();
            v.push_back(x+z-y);
        }
    }
    while(!v.empty()) {
        ans += max(v.front(), v.back()) * cur;
        if(v.front() > v.back()) v.pop_front();
        else v.pop_back();
        cur = -cur;
    }
    cout << (accumulate(a, a+n, 0ll) + ans >> 1);
    return 0;
}