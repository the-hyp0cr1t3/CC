/* GP hash table, an alternative to unordered_map w/ custom hash */

/*
    - pbds gp hash table (better than unordered_map)
        https://codeforces.com/blog/entry/60737
    - custom hash, blowing up unordered_map
        https://codeforces.com/blog/entry/62393
*/

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