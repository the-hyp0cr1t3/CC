/* Gaussian Elimination */

/*
    Blog:
        https://codeforces.com/blog/entry/68953
    General RREF:
        https://cp-algorithms.com/linear_algebra/linear-system-gauss.html
    Problems:
        https://codeforces.com/contest/1101/problem/G
        https://codeforces.com/contest/895/problem/C
        https://www.codechef.com/problems/XORCMPNT
        https://codeforces.com/gym/102920/problem/J
*/

// Use int or int64_t for upto 63 bits
struct BinarySpan {
    vector<int> basis;

    int reduce(int x) {             // if reduce(x) == 0, x is spanned by basis
        for(auto& v: basis)
            x = min(x, x ^ v);
        return x;
    }

    bool add(int x) {
        if(x = reduce(x))           // unordered
            basis.push_back(x);
        // if(x = reduce(x))        // ordered by pivot (MSB)
            // basis.insert(upper_bound(all(basis), x, greater{}), x);
        return !!x;
    };

    int max_xor() {
        int x = 0;
        for(auto& v: basis)
            x = max(x, x ^ v);
        return x;
    }

    int rank() const { return (int)basis.size(); }
};

// Bitset version
template<int N>
struct BinarySpan {
    vector<bitset<N>> basis;

    bitset<N> reduce(bitset<N> x) const {
        for(auto& v: basis)
            if(x[v._Find_first()]) x ^= v;
        return x;
    }

    bool add(bitset<N> x) {
        if((x = reduce(x)).any())
            basis.insert(upper_bound(all(basis), x,
                [](const auto& A, const auto& B) {
                    return A._Find_first() < B._Find_first();
                }), x);
        return x.any();
    }

    int rank() const { return (int)basis.size(); }
};

// Binary RREF
int gauss(int n, int m, vector<bitset<N>>& a) {
    int pivots = 0;
    for(int i = 0, j = 0, k; j < m; j++) {
        for(k = i; k < n and !a[k][j]; k++);
        if(k == n) continue;
        swap(a[k], a[i]);
        for(k = 0; k < n; k++)
            if(k ^ i and a[k][j])
                a[k] ^= a[i];
        i++; pivots++;
    }

    return pivots;
}