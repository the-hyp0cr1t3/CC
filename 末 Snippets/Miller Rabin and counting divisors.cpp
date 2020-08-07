// Count divisors in O(n^1/3)
#define int long long
using u128 = __int128_t;
const int N = 1e2 + 5;
vector<int> primes;
vector<bool> prime;

int expo(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while(exp) {
        if(exp & 1)
            result = (int)((u128)result * base % mod);
        base = (int)((u128)base * base % mod);
        exp >>= 1;
    }
    return result;
}

bool check_composite(int n, int a, int d, int s) {
    int x = expo(a, d, n);
    if(x == 1 || x == n - 1)
        return false;
    for(int r = 1; r < s; r++) {
        x = (int)((u128)x * x % n);
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(int n) {
    if(n < 2)
        return false;

    int r = 0;
    int d = n - 1;
    while((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if(n == a)
            return true;
        if(check_composite(n, a, d, r))
            return false;
    }
    return true;
}

bool isPrime(int n) {
    return MillerRabin(n);
}

int count_divisors(int n) {
    int i, ans = 1;
    for(auto& p: primes) {
        if(p*p*p > n) break;
        int cnt = 0;
        while(n%p == 0)
            cnt++, n /= p;
        ans *= cnt+1;
    }
    int x = (int)sqrt(n);
    if(MillerRabin(n))
        ans *= 2;
    else if(x*x == n and MillerRabin(x))
        ans *= 3;
    else if(n != 1)
        ans *= 4;
    return ans;
}

void sieve(int maxn) {
    primes.reserve(maxn/100);
    prime.assign(maxn, true);
    prime[0] = prime[1] = false;

    primes.push_back(2);
    for(int i = 4; i < maxn; i+=2)
        prime[i] = false;

    for(int i = 3; i*i < maxn; i+=2) {
        if(prime[i]) {
            for(int j = i*i; j < maxn; j+=i*2) {
                if(prime[j]) prime[j] = false;
            }
        }
    }

    for(int i = 3; i < maxn; i+=2) 
        if(prime[i]) primes.push_back(i);
};