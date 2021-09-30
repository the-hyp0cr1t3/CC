/* Longest increasing subsequence */

/*
    https://github.com/the-hyp0cr1t3/CC/blob/master/Beginner%20Topics/%5BS4%5D%20Boohoo~%20It%27s%20dp%20time/%5BEP%205%5D%20LIS.md
*/

template<class T>
int LIS(const vector<T>& v) {
    vector<T> lis; lis.reserve(v.size());
    for(auto& x: v) {
        auto it = lower_bound(lis.begin(), lis.end(), x);       // upper_bound for non strictly increasing
        if(it == lis.end()) lis.push_back(x);
        else *it = x;
    } return lis.size();
}


// Retrieve indices
template<class T>
vector<int> LIS(const vector<T>& v) {
    vector<int> lis, path(v.size(), -1); lis.reserve(v.size());
    for(int z = 0; z < v.size(); z++) {
        auto it = lower_bound(lis.begin(), lis.end(), z, [&v](int A, int B) { return v[A] < v[B]; });      // upper_bound for non strictly increasing
        if(it != lis.begin()) path[z] = *prev(it);
        if(it == lis.end()) lis.push_back(z);
        else *it = z;
    }
    int cur = lis.back();
    vector<int> res; res.reserve(lis.size());
    while(~cur) res.push_back(cur), cur = path[cur];
    return reverse(res.begin(), res.end()), res;
}
