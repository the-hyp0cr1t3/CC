/* Z algorithm */

/*
    https://cp-algorithms.com/string/z-function.html
    See also: KMP
*/

// z[i] is the longest proper prefix
// that is starts at position i
// aaa.aaaba
// 021 32101
auto generate_z = [](const string& s) {
    // s = (pattern + '#' + text)
    int n = s.size();
    vector<int> z(n);
    for(int k = 1, l = 0, r = 0; k < n; ++k) {
        if(k <= r)
            z[k] = min(r - k + 1, z[k - l]);
        while(k + z[k] < n and s[z[k]] == s[k + z[k]])
            z[k]++;
        if(k + z[k] - 1 > r)
            l = k, r = k + z[k] - 1;
    }
    return z;
};
