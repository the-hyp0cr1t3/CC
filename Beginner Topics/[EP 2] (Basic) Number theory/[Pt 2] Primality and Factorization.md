# Prime factorization and Prime sieve
A number is said to be prime if it is not $1$ and is only divisible by itself and $1$. One way to check primality is to factorize the number.

<details>
    <summary>How to check divisibility?</summary>
    In C/C++ the modulo operator % can be used to check divisibility. If x is divisible by y, then x % y will evaluate to 0, otherwise it will be non-zero.
</details>

## Finding all the factors of a number
To find the all the factors of a number $n$, you don't have to check divisibility for all numbers from $1$ to $n$. Instead you can check each number $i$ from $1$ to $\sqrt{n}$. If $i$ divides $n$, then $i$ is a factor of $n$, and so is $n/i$.

**Proof:** Let $n = a * b$, then **either one of a and b have to be less than or equal to $√n$**. Otherwise $a * b$ will obviously be greater than $n$.

[Implementation](https://p.ip.fi/nsPJ)

**Note:** Make sure not to overcount in the case when $n$ is a perfect square because $i$ and $n/i$ would both be $√n$).

**Time complexity:** $O(√n)$

## Finding the prime factorization of a number
For e.g. prime factorization of $60$ is $2 * 2 * 3 * 5$.

[Implementation](https://p.ip.fi/n8tX).

Why does this work?

**Time complexity:** $O(√n)$

#### Problems
* [Codeforces 26A](https://codeforces.com/contest/26/problem/A)








## Prime factorization
Prime factorization of a number can be done efficiently in **O(√N)** time.

[Tutorial](https://cp-algorithms.com/algebra/factorization.html)

#### Problems
* [Spoj FACT0](https://www.spoj.com/problems/FACT0/)
* [Spoj FACTCG2](https://www.spoj.com/problems/FACTCG2/) ([Solution](http://p.ip.fi/ZcNP))
* [Codeforces 26 A](https://codeforces.com/contest/26/problem/A)

## Prime sieve
The sieve of Eratosthenes is one of the most efficient ways to find all primes upto N in **O(N.log(log N))** time and **O(N)** space.

[Tutorial](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html)

#### Problems
* [Spoj DIV](https://www.spoj.com/problems/DIV/)
* [Codeforces 17 A](https://codeforces.com/problemset/problem/17/A)
* [Codeforces 154 B](https://codeforces.com/problemset/problem/154/B)

#### Come back later for
* [Codeforces 111 B](https://codeforces.com/problemset/problem/111/B)
* [Codeforces 584 D](https://codeforces.com/contest/584/problem/D)

Prime factorization using sieve for multiple queries in **O(log N)** per query: [Link](https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/)
