```c++
auto LIS = [&] (vector<int>& v) {
    vector<int> lis; lis.reserve(n);
    for(i = 0; i < n; i++) {
        // v[A] <= v[B] for strictly incr, v[A] < v[B] otherwise
        auto it = upper_bound(all(lis), i, [&](const auto& A, const auto& B) { 
            return v[A] <= v[B];
        });
        int idx = int(it - lis.begin());
        if(it == lis.end()) lis.pb(i);
        else lis[idx] = i;
    }
    return sz(lis);
};

```

With path:
```c++
auto LIS = [&] (vector<int>& v) {
    vector<int> lis; lis.reserve(n);
    vector<int> path(n, -1), res; res.reserve(n);
    for(i = 0; i < n; i++) {
        // v[A] <= v[B] for strictly incr, v[A] < v[B] otherwise
        auto it = upper_bound(all(lis), i, [&](const auto& A, const auto& B) { 
            return v[A] <= v[B];
        });
        int idx = int(it - lis.begin());
        if(it == lis.end()) lis.pb(i);
        else lis[idx] = i;
        if(idx) path[i] = lis[idx-1];
    }
    int cur = lis.back();
    while(~cur) res.pb(cur), cur = path[cur];
    reverse(all(res));
    return res;
};

```