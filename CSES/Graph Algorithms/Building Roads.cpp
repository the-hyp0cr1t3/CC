/**
 🍪 the_hyp0cr1t3
 🍪 17.05.2021 22:26:38
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m;
    cin >> n >> m;

    vector<int> par(n, -1);
    auto get_par = [&par](int A) {
        while(par[A] >= 0) {
            if(par[par[A]] >= 0) par[A] = par[par[A]];
            A = par[A];
        } return A;
    };

    auto merge = [&get_par, &par](int A, int B) {
        A = get_par(A); B = get_par(B);
        if(A == B) return false;
        if(-par[A] < -par[B]) swap(A, B);
        par[A] += par[B]; par[B] = A;
        return true;
    };

    while(m--) {
        int u, v; cin >> u >> v;
        merge(--u, --v);
    }

    int x = -1;
    vector<pair<int, int>> ans;
    for(i = 0; i < n; i++) {
        if(par[i] < 0) {
            if(~x) ans.pb(x, i);
            x = i;
        }
    }

    cout << sz(ans) << '\n';
    for(auto& [x, y]: ans)
        cout << x+1 << ' ' << y+1 << '\n';
} // ~W