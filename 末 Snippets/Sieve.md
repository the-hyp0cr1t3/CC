```c++
vector<int> primes;
vector<int> spf;
vector<bool> prime;

auto sieve = [&] (int maxn) {
    primes.reserve(maxn/100);
    prime.assign(maxn, true);
    spf.assign(maxn, 0);
    prime[0] = prime[1] = false;

    primes.pb(2);
    spf[2] = 2;
    for(i = 4; i < maxn; i+=2)
        prime[i] = false, spf[i] = 2;

    for(i = 3; i*i < maxn; i+=2) {
        if(prime[i]) {
            for(int j = i*i; j < maxn; j+=i*2) {
                if(prime[j]) 
                    prime[j] = false, spf[j] = i;
            }
        }
    }

    for(i = 3; i < maxn; i+=2) {
        if(prime[i]) {
            primes.pb(i);
            spf[i] = i;
        }
    }
};

```