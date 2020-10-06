#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class key, class value = null_type, class cmp = std::less<key>>
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key    // count of elements strictly smaller than k
#define fbo find_by_order   // iterator to kth element starting from 0

ordered_set<int> os;

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
