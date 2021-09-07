/* 0-k Knapsack */

/*
    Given n items and a knapsack of size s,
    i-th item has weight w[i], value v[i] and can be used k[i] times
    maximize total value
    Time complexity: O(ns)
    Algorithms Live Video: https://www.youtube.com/watch?v=U4O3SwDamA4
*/

int64_t _0kKnapsack(int n, int s, vector<int>& w, vector<int>& v, vector<int>& k) {
    auto dist = [](int i, int j, int w) { return abs(i - j) / w; };
    vector<int64_t> dp(s + 1);
    for(int i = 0; i < n; i++) {
        for(int j, m = s; m > s - w[i] and m >= 0; m--) {           // each congruent class (modulo w[i])
            deque<int> maxq;
            for(j = m; j >= 0; j -= w[i]) {
                while(!maxq.empty() and
                        dp[j] + dist(j, maxq.back(), w[i]) * v[i] >= dp[maxq.back()])
                    maxq.pop_back();
                maxq.push_back(j);

                while(dist(j, maxq.front(), w[i]) >= k[i])
                    maxq.pop_front();

                int x = j + k[i] * w[i];
                if(x <= s)
                    dp[x] = max(dp[x], dp[maxq.front()] + dist(maxq.front(), x, w[i]) * v[i]);
            }
            for(j = min(m, j + k[i] * w[i]); j >= 0; j -= w[i]) {
                while(!maxq.empty() and maxq.front() >= j)
                    maxq.pop_front();
                if(!maxq.empty())
                    dp[j] = max(dp[j], dp[maxq.front()] + dist(maxq.front(), j, w[i]) * v[i]);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}