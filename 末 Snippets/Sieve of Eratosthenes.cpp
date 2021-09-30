/* Sieve of Eratosthenes */

/*
    https://github.com/the-hyp0cr1t3/CC/blob/master/Beginner%20Topics/%5BS2%5D%20Primal%20proficiency/%5BEP%202%5D%20Primality%2C%20Factorization%20and%20Sieve.md
*/

const int N = 1e7;
// spf = smallest prime factor
array<int, N> spf; iota(spf.begin(), spf.end(), 0);
vector<int> primes{2}; primes.reserve(N);
for(int z = 4; z < N; z += 2) spf[z] = 2;
for(int z = 3; z*z < N; z += 2) if(spf[z] == z) {
    for(int y = z*z; y < N; y += z*2)
        if(spf[y] == y) spf[y] = z;
}
for(int z = 3; z < N; z += 2) 
    if(spf[z] == z) primes.push_back(z);
