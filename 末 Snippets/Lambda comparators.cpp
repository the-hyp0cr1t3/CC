// Sorting
#define all(x) x.begin(), x.end()

vector<pii> v;

sort(all(v), [&](const auto& A, const auto& B) { 
    // ...
    // for pairs
    if(A.second == B.second)
        return A.first < B.first;
    return A.second < B.second;
});

// STL set and priority_queue comparators
struct lmao {
    int val;
    lmao(int val) : val(val) {}
};

auto cmp = [] (const lmao& A, const lmao& B) {
    return A.val < B.val;
};

set<lmao, decltype(cmp)> s(cmp);
priority_queue <lmao, vector<lmao>, decltype(cmp)> pq(cmp);
