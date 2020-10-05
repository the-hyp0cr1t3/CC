// String hashing (https://codeforces.com/blog/entry/60445)

int genbase(int l, int r) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int base = uniform_int_distribution<int>(l+1, r-1)(rng);
    return base&1? base : base-1;
}

struct hash_t {
    static const int mod = 1e9+123;
    static int base;
    static vector<int> pow1;
    static vector<uint64_t> pow2;
    vector<int> suf1;
    vector<uint64_t> suf2;

    hash_t(const string& s): suf1(sz(s)+1), suf2(sz(s)+1) {
        assert(base < mod); const int n = sz(s);
        pow1.reserve(n+1); pow2.reserve(n+1);
        while(sz(pow1) <= n) {
            pow1.pb(1LL * pow1.back() * base % mod);
            pow2.pb(pow2.back() * base);
        }

        for(int i = n-1; ~i; i--) {
            suf1[i] = (1ll * suf1[i+1] * base + s[i]) % mod;
            suf2[i] = suf2[i+1] * base + s[i];
        }
    }

    pair<int, uint64_t> operator()(int l, int r) {
        int res1 = suf1[l] - 1ll * suf1[r+1] * pow1[r-l+1] % mod;
        res1 = res1 < 0? res1 + mod : res1;
        uint64_t res2 = suf2[l] - suf2[r+1] * pow2[r-l+1];
        return {res1, res2};
    }
};
int hash_t::base = genbase(256, hash_t::mod);
vector<int> hash_t::pow1{1};
vector<uint64_t> hash_t::pow2{1};

// string s; hash_t hsh(s);


// ------------------------------------------------------------------------
// Custom hash using splitmix64 (https://codeforces.com/blog/entry/62393)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// ------------------------------------------------------------------------
// gp_hash_table, a better alternative to std::unordered_map (https://codeforces.com/blog/entry/60737)
#include <ext/pb_ds/assoc_container.hpp>
__gnu_pbds::gp_hash_table<int, int> table;

// write a custom hash for different keys, something like
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(const pair<uint64_t, uint64_t>& x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.second + FIXED_RANDOM) ^ (splitmix64(FIXED_RANDOM + x.first) << 1);
    }
};
__gnu_pbds::gp_hash_table<pair<int, int>, int, custom_hash> table;
