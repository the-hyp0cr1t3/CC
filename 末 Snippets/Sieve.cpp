/* Sieve of Eratosthenes */
// (https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html)

const int N = 1e7;
// spf = smallest prime factor
array<int, N> spf; iota(all(spf), 0);
vector<int> primes{2}; primes.reserve(N);
for(int z = 4; z < N; z += 2) spf[z] = 2;
for(int z = 3; z*z < N; z += 2)
    if(spf[z] == z) for(int y = z*z; y < N; y += z*2)
        if(spf[y] == y) spf[y] = z;
for(int z = 3; z < N; z += 2) 
    if(spf[z] == z) primes.pb(z);
