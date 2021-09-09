/* Sets, priority queues & sorting vectors with custom comparators */

vector<pair<int, int>> v;
sort(v.begin(), v.end(), [](const auto& A, const auto& B) {
    // ...
    // for pairs
    return A.second == B.second?
                A.first < B.first : A.second < B.second;
});


// STL set and priority_queue comparators
auto cmp = [](const auto& A, const auto& B) {
    return A < B;
};

set<T, decltype(cmp)> s(cmp);
priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

