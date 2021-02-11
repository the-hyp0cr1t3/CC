/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 17:31:52
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
 
const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 1e6 + 5;
int c[N], dp[N];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, S;
    cin >> n >> S;
    for(i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c+n);
 
    dp[0] = 1;
    for(i = 0; i < S; i++)
        for(j = 0; j < n; j++)
            if(i + c[j] <= S)
                (dp[i+c[j]] += dp[i]) %= MOD;
    
    cout << dp[S];
} // ~W 


/* Recursive~ */

/**
 🍪 the_hyp0cr1t3
 🍪 12.01.2021 15:45:41
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
const int N = 100 + 5;
const int M = 1e6 + 5;
int weights[N], cache[M];
 
int dp(int S) {
    if(S < 0) return 0;
    int& ans = cache[S];
    if(~ans) return ans;
    ans = 0;
    for(int i = 0; weights[i] <= S; i++) {
        ans += dp(S - weights[i]);
        if(ans >= MOD) ans -= MOD;
    } return ans;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, S;
    cin >> n >> S;
    for(i = 0; i < n; i++)
        cin >> weights[i];
    sort(weights, weights + n);
    weights[n] = INF;
    memset(cache, -1, sizeof(cache));
    cache[0] = 1;
    cout << dp(S);
} // ~W 