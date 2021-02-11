/**
 🍪 the_hyp0cr1t3
 🍪 02.02.2021 23:25:43
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
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };
 
const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 20;
int a[N];
array<array<int, 2>, 1 << N> dp;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, S;
    cin >> n >> S;
    for(i = 0; i < n; i++)
        cin >> a[i];
 
    dp.fill({INF, INF}); dp[0] = {1, 0};
    for(int msk = 1; msk < 1<<n; msk++) {
        for(i = 0; i < n; i++) {
            if(msk>>i&1) {
                auto cand = dp[msk ^ 1<<i];
                cand[1] += a[i];
                if(cand[1] > S)
                    cand[0]++, cand[1] = a[i];
                chmin(dp[msk], cand);
            }
        }
    } cout << dp[(1<<n)-1][0];
 
} // ~W 