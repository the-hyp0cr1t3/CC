/**
 🍪 thew6rst
 🍪 10.02.2021 15:48:39
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
    int i, n;
    cin >> n;
    vector<int> a(n);
    stack<int> st;
    for(i = 0; i < n; i++) {
        cin >> a[i];
        while(!st.empty() and a[st.top()] >= a[i])
            st.pop();
        cout << (st.empty()? 0 : st.top() + 1) << " \n"[i == n-1];
        st.push(i);
    }
} // ~W 