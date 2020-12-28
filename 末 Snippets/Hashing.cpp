#include <ext/pb_ds/assoc_container.hpp>
namespace Hashing {    
    using hash_t = pair<int, uint64_t>;
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    
    // Custom hash using splitmix64 (https://codeforces.com/blog/entry/62393)
    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const {
            return splitmix64(x + FIXED_RANDOM);
        }
        size_t operator()(const hash_t& x) const {
            return splitmix64(FIXED_RANDOM + x.second)
                    ^ (splitmix64(FIXED_RANDOM + x.first) << 1);
        }
    };
    
    // gp_hash_table benchmarks vs unordered_map (https://codeforces.com/blog/entry/60737)
    template<typename K, typename V, typename Hash = custom_hash>
    using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
    
    template<typename K, typename Hash = custom_hash>
    using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;
}

namespace Hashing {
    using hash_t = pair<int, uint64_t>;
    vector<uint64_t> pow2{1};

    template<const int& base, int mod>
    struct double_hash {
        static inline vector<int> pow1{1};
        const int n;
        vector<int> suf1;
        vector<uint64_t> suf2;

        double_hash(const string& s): n(s.size()), suf1(n+1), suf2(n+1) {
            assert(base < mod);
            pow1.reserve(n+1); pow2.reserve(n+1);
            while((int)pow1.size() <= n)
                pow1.push_back(1LL * pow1.back() * base % mod);
            while((int)pow2.size() <= n)
                pow2.push_back(pow2.back() * base);
            for(int i = n-1; ~i; i--) {
                suf1[i] = (1ll * suf1[i+1] * base + s[i]) % mod;
                suf2[i] = suf2[i+1] * base + s[i];
            }
        }

        hash_t operator()(int l, int r) const {
            int res1 = suf1[l] - 1ll * suf1[r+1] * pow1[r-l+1] % mod;
            res1 = res1 < 0? res1 + mod : res1;
            uint64_t res2 = suf2[l] - suf2[r+1] * pow2[r-l+1];
            return {res1, res2};
        }
        hash_t operator()() const { return (*this)(0, n-1); }
    };

#ifndef __MOD_BASE
    #define __MOD_BASE 
    constexpr int _mod = 1e9+123;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    static const int _base = uniform_int_distribution<int>(256, _mod-2)(rng) | 1;
#endif
    template<const int& base = _base, int mod = _mod>
    using string_double_hash = double_hash<base, mod>;
}

namespace Hashing {
    template<const int& base, int mod>
    struct single_hash {
        static inline vector<int> pows{1};
        const int n;
        vector<int> suf;
        single_hash(const string& s): n(s.size()), suf(n+1) {
            assert(base < mod);
            pows.reserve(n+1);
            while((int)pows.size() <= n)
                pows.push_back(1LL * pows.back() * base % mod);
            for(int i = n-1; ~i; i--)
                suf[i] = (1ll * suf[i+1] * base + s[i]) % mod;
        }
        int operator()(int l, int r) const {
            int res = suf[l] - 1ll * suf[r+1] * pows[r-l+1] % mod;
            return res < 0? res + mod : res;
        }
        int operator()() const { return (*this)(0, n-1); }
    };

#ifndef __MOD_BASE
    #define __MOD_BASE 
    constexpr int _mod = 1e9+123;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    static const int _base = uniform_int_distribution<int>(256, _mod-2)(rng) | 1;
#endif
    template<const int& base = _base, int mod = _mod>
    using string_single_hash = single_hash<base, mod>;
}

/*
int main() {
    string s = "absedfdsd";
    Hashing::string_double_hash<> single_hash(s);
    Hashing::string_single_hash<> double_hash(s);
    
    cout << single_hash(3, 4) << '\n';
    auto [x, y] = double_hash();
    cout << x << ' ' << y;
}
*/
