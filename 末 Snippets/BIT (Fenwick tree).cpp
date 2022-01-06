/* Binary Indexed Tree (BIT) */

// T -> type, ONE -> indexing
template <class T, bool ONE = true>
struct BIT {
    int N; vector<T> bit;
    BIT() = default;
    BIT(int N): N(N), bit(N + 1) {}

    BIT(const vector<T>& a) : N(a.size()), bit(N + 1) {
        for(int i = 1; i <= N; i++) {
            bit[i] += a[i-1];
            if(i + (i & -i) <= N)
                bit[i + (i & -i)] += bit[i];
        }
    }

    T query(int i) {
        T res = 0;
        for(i += !ONE; i; i -= i & -i)
            res += bit[i];
        return res;
    }

    T query(int l, int r) {
        if(l > r) return T();
        return query(r) - query(l - 1);
    }

    void update(int i, T val) {
        for(i += !ONE; i <= N; i += i & -i)
            bit[i] += val;
    }
};