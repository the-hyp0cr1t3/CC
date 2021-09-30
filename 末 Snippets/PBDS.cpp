/* Policy Based Data Structures - ordered_set */

/*
    https://codeforces.com/blog/entry/11080

    Problems:
        https://codeforces.com/contest/1324/problem/D
        https://codeforces.com/contest/255/problem/C
        https://cses.fi/problemset/task/2168
        https://cses.fi/problemset/task/2169
        https://cses.fi/problemset/task/2163
        https://codeforces.com/contest/1262/problem/D2
        https://codeforces.com/contest/1311/problem/F
        https://codeforces.com/contest/1191/problem/F
        https://codeforces.com/contest/1401/problem/E
        https://codeforces.com/contest/1005/problem/E2
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class key, class value = null_type, class cmp = std::less<key>>
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key    // count of elements strictly smaller than k
#define fbo find_by_order   // iterator to kth element starting from 0

ordered_set<int> os;
ordered_set<pair<int, int>> os;
ordered_set<int, int> o_map;
ordered_set<int, null_type, std::greater<int>> os_greater;