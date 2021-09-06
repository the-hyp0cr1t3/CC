/**
 🍪 the_hyp0cr1t3
 🍪 06.09.2021 01:01:32
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
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, mx = 1;
    cin >> n >> m;

    vector<int> par(n + 1, -1);
    auto get_par = [&par](int A) {
        while(par[A] >= 0) {
            if(par[par[A]] >= 0)
                par[A] = par[par[A]];
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
        if(merge(u, v)) n--;
        mx = max(mx, -par[get_par(u)]);
        cout << n << ' ' << mx << '\n';
    }

} // ~W