// Inspired by Neal's amazing template
// [neal's submission](https://codeforces.com/contest/1096/submission/47700940)
// [my submission](https://codeforces.com/contest/1096/submission/119566645)

namespace NTT {
    const int FFT_CUTOFF = 150;
    vector<mint> roots = {0, 1};
    vector<int> bit_order;
    int max_size = 1;       // MOD = c∙2^k + 1, maxsize = 2^k
    mint root = 2;          // n must not exceed maxsize

    auto find_root = []() {
        int order = MOD-1;
        while(~order & 1) order >>= 1, max_size <<= 1;
        while((root ^ max_size) != 1 or (root ^ max_size/2) == 1)
            root++;
        return 'W';
    }();

    void prepare_roots(int n) {
        if(sz(roots) >= n) return;
        int len = __builtin_ctz(sz(roots));
        roots.resize(n);
        while(n > 1 << len) {
            mint z = root ^ max_size >> len + 1;
            for(int i = 1 << len-1; i < 1 << len; i++) {
                roots[i << 1] = roots[i];
                roots[i << 1 | 1] = roots[i] * z;
            } len++;
        }
    }

    void reorder_bits(int n, vector<mint>& a) {
        if(sz(bit_order) != n) {
            bit_order.assign(n, 0);
            int len = __builtin_ctz(n);
            for(int i = 0; i < n; i++)
                bit_order[i] = (bit_order[i >> 1] >> 1) + ((i & 1) << len-1);
        }
        for(int i = 0; i < n; i++)
            if(i < bit_order[i]) swap(a[i], a[bit_order[i]]);
    }

    void fft(int n, vector<mint>& a) {
        assert(n <= max_size);
        prepare_roots(n); reorder_bits(n, a);
        for(int len = 1; len < n; len <<= 1)
            for(int i = 0; i < n; i += len << 1)
                for(int j = 0; j < len; j++) {
                    const mint& even = a[i + j];
                    mint odd = a[i + len + j] * roots[len + j];
                    a[i + len + j] = even - odd; a[i + j] = even + odd;
                }
    }

    template<typename T>
    vector<mint> multiply(const vector<T>& a, const vector<T>& b, bool trim = false) {
        int n = sz(a), m = sz(b);
        if(n == 0 or m == 0)
            return vector<mint>{0};

        if(min(n, m) < FFT_CUTOFF) {
            vector<mint> res(n + m - 1);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    res[i + j] += mint(a[i]) * mint(b[j]);
            
            if(trim) {
                while(!res.empty() && res.back() == 0)
                    res.pop_back();
            }

            return res;
        }

        int N = [](int x) { while(x & x-1) x = (x | x-1) + 1; return x; }(n + m - 1);
        vector<mint> fa(all(a)), fb(all(b));
        fa.resize(N); fb.resize(N);

        bool equal = fa == fb;
        fft(N, fa);

        if(equal) fb = fa;
        else fft(N, fb);

        mint inv_N = mint(N) ^ -1;
        for(int i = 0; i < N; i++)
            fa[i] *= fb[i] * inv_N;
        reverse(fa.begin() + 1, fa.end());

        fft(N, fa);
        fa.resize(n + m - 1);

        if(trim) {
            while(!fa.empty() && fa.back() == 0)
                fa.pop_back();
        }

        return fa;
    }

    template<typename T>
    vector<mint> expo(const vector<T>& a, int e, bool trim = false) {
        int n = sz(a);
        int N = [](int x) { while(x & x-1) x = (x | x-1) + 1; return x; }((n-1) * e + 1);
        vector<mint> fa(all(a)); fa.resize(N);

        fft(N, fa);

        mint inv_N = mint(N) ^ -1;
        for(int i = 0; i < N; i++)
            fa[i] = (fa[i] ^ e) * inv_N;
        reverse(fa.begin() + 1, fa.end());

        fft(N, fa);
        fa.resize((n-1) * e + 1);

        if(trim) {
            while(!fa.empty() && fa.back() == 0)
                fa.pop_back();
        }

        return fa;
    }

} // namespace NTT 
