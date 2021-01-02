/* nCr | Combination(n, r) | N choose R ~ n things taken r at a time without repetition */
// Note: Mod operations are implicitly handled by ModInt struct mint
// Note2: May also be used without, by performing required mod ops where necessary

int maxN = 1e6;

static vector<mint> fact{1, 1}, factinv{1, 1}, inv{0, 1};
[](int N) {
    fact.reserve(N); factinv.reserve(N); inv.reserve(N);
    for(int z = fact.size(); z < N; z++) {
        // [Modular inverse](https://cp-algorithms.com/algebra/module-inverse.html#mod-inv-all-num)
        inv.push_back(inv[MOD % z] * (MOD - MOD / z));
        fact.push_back(z * fact[z-1]);
        factinv.push_back(inv[z] * factinv[z-1]);            
    }
}(maxN);

auto nCr = [&](int n, int r) {
    return r < 0 or r > n? 0 : fact[n] * factinv[r] * factinv[n-r];
};
