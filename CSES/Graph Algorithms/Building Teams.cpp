/**
 🍪 the_hyp0cr1t3
 🍪 17.05.2021 22:46:57
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

    vector<int> par(n, -1), val(n);
    auto get_par = [&par, &val](int A) {
        int v = 0;
        while(par[A] >= 0) {
            if(par[par[A]] >= 0) {
                val[A] ^= val[par[A]];
                par[A] = par[par[A]];
            } v ^= val[A], A = par[A];
        } return pair{ A, v ^ val[A] };
    };

    auto merge = [&get_par, &par, &val](int _A, int _B) {
        auto[A, a] = get_par(_A);
        auto [B, b] = get_par(_B);
        if(A == B) return a ^ b;
        if(-par[A] < -par[B]) swap(A, B);
        par[A] += par[B]; par[B] = A;
        val[B] = a ^ b ^ 1;
        return 1;
    };

    while(m--) {
        int u, v; cin >> u >> v;
        if(!merge(--u, --v))
            return cout << "IMPOSSIBLE" << '\n', 0;
    }

    for(i = 0; i < n; i++)
        cout << get_par(i).second + 1 << " \n"[i == n-1];
} // ~W