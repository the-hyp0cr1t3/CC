/*
0-k knapsack
O(N*S)
1 <= N,S <= 2000
1 <= w_i, k_i, v_i <= 1e9
Inspired by: [https://www.youtube.com/watch?v=U4O3SwDamA4]
*/
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define bk back
#define fr front
const int N = 2000 + 5;
int w[N], k[N], v[N];
long long dp[N];

int32_t main() {
    IOS;
    int i, j, n, S;
    cin >> n >> S;
    for(i = 0; i < n; i++)
        cin >> w[i];
    for(i = 0; i < n; i++)
        cin >> k[i];
    for(i = 0; i < n; i++)
        cin >> v[i];

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    auto dist = [&](int a, int b) {
        return (b-a)/w[i];
    };
    auto chmax = [](auto& a, auto&& b) { 
        a = max(a, b); 
    };

    for(i = 0; i < n; i++) {
        for(int z = S; S-z < w[i] and z >= 0; z--) {    // each congruent class (modulo w[i])
            deque<int> q;                       // max queue (O(1) amortized) sliding window: size-k[i]
            for(j = z; j >= 0; j -= w[i]) {
                if(~dp[j]) {
                    while(!q.empty() and dp[j] + dist(j, q.bk()) * v[i] >= dp[q.bk()])      // slopes are all the same
                        q.pop_back();                                                       // differences constant
                    q.push_back(j);
                }

                while(!q.empty() and dist(j, q.fr()) >= k[i]) 
                    q.pop_front();

                int nxt = j+k[i]*w[i];
                if(!q.empty() and nxt <= S)
                    chmax(dp[nxt], dp[q.fr()] + dist(q.fr(), nxt) * v[i]);
            }
            for(j = min(j+k[i]*w[i], z); j >= 0; j -= w[i]) {
                while(!q.empty() and q.fr() >= j) 
                    q.pop_front();
                if(!q.empty())
                    chmax(dp[j], dp[q.fr()] + dist(q.fr(), j) * v[i]);
            }
        }
    }

    cout << *max_element(dp, dp+S+1);
    return 0;
}