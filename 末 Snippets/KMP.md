```c++
auto generate_pi = [&] (string s) {
    // s = (pattern + '#' + text) 
    int n = sz(s);
    vector<int> pi(n);
    for(i = 1; i < n; i++) {
        int p = pi[i-1];
        while(p and s[i] != s[p]) p = pi[p-1];
        pi[i] = p + (s[i] == s[p]);
    }
    return pi;
};
/*  Getting all lengths ending at x-th pos
        while(pi[x]) {
            add pi[x] to ans
            x = pi[x]-1
        }
    Number of occurrences of each prefix
        for i from '#' to end
            pref[pi[i]]++
        for i = n to 1
            pref[pi[i-1]] += pref[i]
*/

```