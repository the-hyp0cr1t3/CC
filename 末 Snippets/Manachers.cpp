/* Palindromic substrings using Manacher's algorithm */
// (https://cp-algorithms.com/string/manacher.html)

auto manachers = [&] (const string& s) {
// a b c b a a b b
// 0 0 0 0 0 2 0 1  -- even length stores len/2
// 1 1 3 1 1 1 1 1  -- odd  length stores (len+1)/2
    int n = s.size();
    array<vector<int>, 2> res;
    vector<int>& even = res[0];
    vector<int>& odd = res[1];
    odd.resize(n); even.resize(n);
    for(int z = 0, l = 0, r = -1; z < n; z++) {
        int k = (z > r) ? 1 : min(odd[l+r-z], r-z+1);
        while(0 <= z-k and z+k < n and s[z-k] == s[z+k]) k++;
        odd[z] = k--;
        if(z+k > r) l = z-k, r = z+k;
    } for(int z = 0, l = 0, r = -1; z < n; z++) {
        int k = (z > r) ? 0 : min(even[l+r-z+1], r-z+1);
        while(0 <= z-k-1 and z+k < n and s[z-k-1] == s[z+k]) k++;
        even[z] = k--;
        if(z+k > r) l = z-k-1, r = z+k;
    } return res;
};
