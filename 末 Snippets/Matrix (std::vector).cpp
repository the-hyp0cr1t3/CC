/* Matrix struct using std::array (slower than array for small sizes) */

/*
    - supports dynamic matrix dimensions

    Blogs:
        http://zobayer.blogspot.com/2010/11/matrix-exponentiation.html
        https://codeforces.com/blog/entry/67776

    Errichto video + blog + gym mashup:
        https://www.youtube.com/watch?v=eMXNWcbw75E_
        https://codeforces.com/blog/entry/80195

    Optimized to O(k^2 logN) using Cayley Hamilton theorem:
        https://discuss.codechef.com/t/linear-recurrence-using-cayley-hamilton-theorem/6776

    Problems:
        https://www.spoj.com/problems/FIBOFAST/
        https://www.spoj.com/problems/MPOW/
        https://www.spoj.com/problems/FIBOSUM/cstart=10
        https://codeforces.com/contest/185/problem/A
        https://codeforces.com/problemset/problem/166/E
        https://codeforces.com/problemset/problem/1117/D
        https://codeforces.com/gym/102644
*/

template<typename T>
struct Matrix {
    int N, M; vector<vector<T>> a;
    
    Matrix(int n, int m): N(n), M(m) , a(n, vector<T>(m)) {}

    explicit Matrix(int n, int m, T x): Matrix(n, m) {
        for(int i = 0; i < min(N, M); i++) a[i][i] = x;
    }
    
    Matrix(initializer_list<vector<T>> x) {
        N = x.size(); M = x.begin()->size(); a.resize(N);
        for(int i = 0; i < x.size(); i++)
            a[i] = *(x.begin() + i), assert(a[i].size() == M);
    }
    
    vector<T>& operator[](size_t x) { return a[x]; }
    const vector<T>& operator[](size_t x) const { return a[x]; }

    friend ostream& operator<<(ostream& out, const Matrix& x) {
        for(int i = 0; i < x.N; i++) 
            for(int j = 0; j < x.M; j++) 
                out << x.a[i][j] << " \n"[j == x.M-1];
        return out;
    }

    Matrix& operator+=(const Matrix& o) {
        assert(N == o.N && M == o.M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] += o[i][j];
        return *this;
    }

    Matrix& operator-=(const Matrix& o) {
        assert(N == o.N && M == o.M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] -= o[i][j];
        return *this;
    }

    Matrix& operator*=(T x) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] *= x;
        return *this;
    }

    Matrix operator*(const Matrix& o) const {
        assert(M == o.N);
        Matrix<T> res(N, o.M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                for(int k = 0; k < o.M; k++)
                    res[i][k] += a[i][j] * o[j][k];
        return res;
    }

    Matrix& operator*=(const Matrix& o) {
        assert(N == M && o.N == o.M && N == o.N);
        return *this = move(*this * o);
    }

    template<typename U, typename = enable_if_t<is_integral<U>::value>>
    Matrix& operator^=(U x) {
        assert(x >= 0 && N == M);
        Matrix res(N, N, 1); while(x) {
            if(x & 1) res *= *this;
            x >>= 1; *this *= *this;
        } return *this = move(res);
    }

    Matrix operator+(const Matrix& o) const { Matrix res = *this; res += o; return res; }
    Matrix operator-(const Matrix& o) const { Matrix res = *this; res -= o; return res; }
    Matrix operator*(T o) const { Matrix res = *this; res *= o; return res; }
    template<typename U, typename = enable_if_t<is_integral<U>::value>>
    Matrix operator^(U x) const { Matrix res = *this; res ^= x; return res; }
};
