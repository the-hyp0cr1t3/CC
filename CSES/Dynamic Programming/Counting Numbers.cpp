/**
 🍪 the_hyp0cr1t3
 🍪 02.02.2021 23:55:33
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
int64_t dp[20][2][10];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int64_t A, B;
    cin >> A >> B;
    
    auto go = [](int64_t n) {
        stringstream ss; string s;
        ss << n; ss >> s; reverse(all(s));
        int64_t ans = 0;
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = dp[0][1][0] = dp[1][0][0] = dp[1][1][0] = 1;
        for(int len = 1; len <= sz(s); len++) {
            for(int j = 0; j < 10; j++) {
                for(int k = 0; k < 10; k++) {
                    dp[len][0][j] += j ^ k? dp[len-1][0][k] : 0;
                    if(j == s[len-1]-'0') {
                        dp[len][1][j] += k ^ j? dp[len-1][1][k] : 0;
                    } else if(j < s[len-1]-'0') {
                        dp[len][1][j] += j ^ k? dp[len-1][0][k] : 0;
                    }
                } if(len == 1 or j) ans += dp[len][len == sz(s)][j];
            }
        } return ans;
    };
 
    cout << go(B) - (A > 0? go(A - 1) : 0);
 
} // ~W 