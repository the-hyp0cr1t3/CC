// ModInt struct num {};
num fact[N], factinv[N], inv[N];

fact[0] = factinv[0] = 1;
fact[1] = factinv[1] = inv[1] = 1;

for(int i = 2; i < N; i++) {
    fact[i] = fact[i-1] * num(i);
    inv[i] = num(-MOD/i) * inv[MOD%i];
    factinv[i] = factinv[i-1] * inv[i];
}

auto nCr = [&] (int n, int r) {
    if (r > n) return num(0);
    num ans = fact[n] * factinv[r] * factinv[n-r];
    return ans;
};

