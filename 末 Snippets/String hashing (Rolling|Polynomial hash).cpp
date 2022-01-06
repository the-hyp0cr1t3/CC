/* String hashing w/ Roling/Polynomial hash */

/*
    Blog:
        https://codeforces.com/blog/entry/60445
    Algorithms Live:
        https://www.youtube.com/watch?v=rA1ZevamGDc
    Problems:
        https://codeforces.com/contest/1326/problem/D2
        https://codeforces.com/contest/835/problem/D
        https://codeforces.com/contest/985/problem/F
    Prefix implementations:
        https://codeforces.com/contest/1469/submission/102644985 (single hash)
        https://codeforces.com/contest/1469/submission/102644888 (double hash)
*/

// Single hash
namespace Hashing {
#ifndef __MOD_BASE
    #define __MOD_BASE
    constexpr int _mod = 1e9 + 123;     // default mod
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    static const int _base = uniform_int_distribution<int>(256, _mod - 2)(rng) | 1;     // random base
#endif

    // use base and primary mod of your choice
    template<const int& base = _base, int mod = _mod>
    struct single_hash {
        static inline vector<int> pows{1};
        int n;
        vector<int> suf;
        void build(const string& s) {
            n = s.size();
            assert(base < mod);
            suf.resize(n + 1); pows.reserve(n + 1);
            while(pows.size() <= n)
                pows.push_back(1LL * pows.back() * base % mod);
            for(int i = n - 1; ~i; i--)
                suf[i] = (1ll * suf[i + 1] * base + s[i]) % mod;
        }

        // hash [l, r)
        int operator()(int l, int r) const {
            int res = suf[l] - 1ll * suf[r] * pows[r - l] % mod;
            return res < 0? res + mod : res;
        }
        int operator()() const { return (*this)(0, n); }
    };

}


// double hash
namespace Hashing {
#ifndef __MOD_BASE
    #define __MOD_BASE
    constexpr int _mod = 1e9 + 123;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    static const int _base = uniform_int_distribution<int>(256, _mod - 2)(rng) | 1;
#endif
    using hash_t = pair<int, uint64_t>;
    vector<uint64_t> pow2{1};

    template<const int& base = _base, int mod = _mod>
    struct double_hash {
        static inline vector<int> pow1{1};
        int n;
        vector<int> suf1;
        vector<uint64_t> suf2;

        void build(const string& s) {
            n = s.size();
            assert(base < mod);
            suf1.resize(n + 1); suf2.resize(n + 1);
            pow1.reserve(n + 1); pow2.reserve(n + 1);
            while(pow1.size() <= n)
                pow1.push_back(1LL * pow1.back() * base % mod);
            while(pow2.size() <= n)
                pow2.push_back(pow2.back() * base);
            for(int i = n - 1; ~i; i--) {
                suf1[i] = (1ll * suf1[i + 1] * base + s[i]) % mod;
                suf2[i] = suf2[i + 1] * base + s[i];
            }
        }

        // hash [l, r)
        hash_t operator()(int l, int r) const {
            int res1 = suf1[l] - 1ll * suf1[r] * pow1[r - l] % mod;
            if(res1 < 0) res1 += mod;
            uint64_t res2 = suf2[l] - suf2[r] * pow2[r - l];
            return {res1, res2};
        }
        hash_t operator()() const { return (*this)(0, n); }
    };

}


/*
int main() {
    string s = "absedfd$%#&@sdA01";
    static const int base = 23;
    Hashing::single_hash<base, int(1e9+7)> A(s);
    Hashing::double_hash<> B(s);

    cout << A(3, 4) << '\n';
    auto [x, y] = B();
    cout << x << ' ' << y;
}
*/