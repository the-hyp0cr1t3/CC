```c++
auto manachers = [&] (vector<int>& odd, vector<int>& even) {
// a b c b a a b b
// 1 1 3 1 1 1 1 1
// 0 0 0 0 0 2 0 1
    odd.resize(n);
    even.resize(n);
    int l = 0, r = -1;
    for(i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(odd[l+r-i], r-i+1);
        while (0 <= i-k and i+k < n and s[i-k] == s[i+k])
            k++;
        odd[i] = k--;
        if (i+k > r)
            l = i-k, r = i+k;
    }
    for(i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(even[l+r-i+1], r-i+1);
        while (0 <= i-k-1 and i+k < n and s[i-k-1] == s[i+k])
            k++;
        even[i] = k--;
        if (i+k > r)
            l = i-k-1, r = i+k;
    }
    for(i = 0; i < n; i++) 
        even[i] *= 2;
};

```