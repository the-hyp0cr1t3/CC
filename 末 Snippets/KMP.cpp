/* KMP */

/*
    https://discuss.codechef.com/t/tutorial-prefix-function-pattern-matching-supposedly-kmp/67531
    https://cp-algorithms.com/string/prefix-function.html
    https://www.youtube.com/watch?v=nJbNe0Yzjhw
    See also: Z algo
*/

// pi[i] is the longest proper prefix
// that is a suffix ending at position i
// abcd.abceab
// 0000 123012
auto generate_pi = [&](const string& s) {
    // s = (pattern + '#' + text) 
    int n = s.size();
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

    Check if it is periodic
    auto check = [](int len, int pi) {
        return pi and len % (len - pi) == 0;
    };
    check(n, pi[n-1]) == true
*/
