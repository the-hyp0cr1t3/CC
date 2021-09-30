/* nCr | Combination(n, r) | N choose R ~ n things taken r at a time without repetition */

/*
    - Mod operations are implicitly handled by ModInt struct mint
    - May also be used without by performing required mod ops where necessary
*/

int maxN = 1e6;

static vector<mint> fact{1, 1}, factinv{1, 1}, inv{0, 1};

fact.reserve(maxN); factinv.reserve(maxN); inv.reserve(maxN);
for(int z = fact.size(); z < maxN; z++) {
    // [Modular inverse](https://cp-algorithms.com/algebra/module-inverse.html#mod-inv-all-num)
    inv.push_back(inv[MOD % z] * (MOD - MOD / z));
    fact.push_back(z * fact[z-1]);
    factinv.push_back(inv[z] * factinv[z-1]);
}

auto nCr = [&](int n, int r) {
    return r < 0 or r > n? 0 : fact[n] * factinv[r] * factinv[n-r];
};
