/* [neal](https://codeforces.com/profile/neal) orz */
// Prime factorizes n in worst case O(sqrt n).
vector<pair<int64_t, int>> prime_factorize(int64_t n) {
    assert(n >= 1);
    vector<pair<int64_t, int>> result;
 
    for(int64_t p = 2; p * p <= n; p++)
        if(n % p == 0) {
            result.emplace_back(p, 0);
 
            do {
                n /= p;
                result.back().second++;
            } while(n % p == 0);
        }
 
    if(n > 1)
        result.emplace_back(n, 1);
 
    return result;
}
 
// This covers up to 2^64. See http://oeis.org/A066150 and http://oeis.org/A036451
const int FACTORS_MAX = 185000;
 
vector<int64_t> generate_factors(const vector<pair<int64_t, int>> &prime_factors, bool sorted = false) {
    static int64_t buffer[FACTORS_MAX];
    int product = 1;
 
    for(auto &pf : prime_factors)
        product *= pf.second;
 
    vector<int64_t> factors = {1};
    factors.reserve(product);
 
    for(auto &pf : prime_factors) {
        int64_t p = pf.first;
        int exponent = pf.second;
        int before_size = int(factors.size());
 
        for(int i = 0; i < exponent * before_size; i++)
            factors.push_back(factors[factors.size() - before_size] * p);
 
        if(sorted && factors[before_size - 1] > p)
            for(int section = before_size; section < int(factors.size()); section *= 2)
                for(int i = 0; i + section < int(factors.size()); i += 2 * section) {
                    int length = min(2 * section, int(factors.size()) - i);
                    merge(factors.begin() + i, factors.begin() + i + section, factors.begin() + i + section, factors.begin() + i + length, buffer);
                    copy(buffer, buffer + length, factors.begin() + i);
                }
    }
    return factors;
}
