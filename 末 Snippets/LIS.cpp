auto LIS = [&] (const vector<int>& v) {
    vector<int> lis; lis.reserve(n);
    for(int z = 0; z < n; z++) {
        // v[A] <= v[B] for strictly incr, v[A] < v[B] otherwise
        auto it = upper_bound(all(lis), z, [&](const auto& A, const auto& B) { 
            return v[A] <= v[B];
        });
        int idx = int(it - lis.begin());
        if(it == lis.end()) lis.pb(z);
        else lis[idx] = z;
    } return sz(lis);           // returns length
};

/* -------------------------------------------------- */
// With path
auto LIS = [&] (const vector<int>& v) {
    vector<int> lis; lis.reserve(n);
    vector<int> path(n, -1), res; res.reserve(n);
    for(int z = 0; z < n; z++) {
        // v[A] <= v[B] for strictly incr, v[A] < v[B] otherwise
        auto it = upper_bound(all(lis), z, [&](const auto& A, const auto& B) { 
            return v[A] <= v[B];
        });
        int idx = int(it - lis.begin());
        if(it == lis.end()) lis.pb(z);
        else lis[idx] = z;
        if(idx) path[z] = lis[idx-1];
    }
    int cur = lis.back();
    while(~cur) res.pb(cur), cur = path[cur];
    return reverse(all(res)), res;          // returns vector of indices
};

