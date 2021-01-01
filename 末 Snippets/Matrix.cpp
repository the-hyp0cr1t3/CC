// Inspired by [this](https://codeforces.com/contest/954/submission/41309586) submission by [LHiC](https://codeforces.com/profile/LHiC)
template<typename T, int N, int M = N>
struct Matrix {
    array<array<T, M>, N> a{};
    Matrix() = default;
    explicit Matrix(T x) { for(int i = 0; i < min(N, M); i++) a[i][i] = x; }
    Matrix(initializer_list<array<T, M>> x) {
        assert(x.size() <= N);
        for(int i = 0; i < x.size(); i++)
            a[i] = *(x.begin() + i);
    }

    array<T, M>& operator[](int x) { return a[x]; }
    const array<T, M>& operator[](int x) const { return a[x]; }
    friend ostream& operator<<(std::ostream& out, const Matrix& x) {
        for(int i = 0; i < N; i++) 
            for(int j = 0; j < M; j++) 
                out << x.a[i][j] << " \n"[j == M-1];
        return out;
    }
    
    Matrix& operator+=(const Matrix& x) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] += x[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& x) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] -= x[i][j];
        return *this;
    }
    
    Matrix operator+(const Matrix& x) const {
        Matrix ans = *this;
        return ans += x;
    }
    Matrix operator-(const Matrix& x) const {
        Matrix ans = *this;
        return ans -= x;
    }
    
    template<int K>
    Matrix<T, N, K> operator*(const Matrix<T, M, K>& x) const {
        Matrix<T, N, K> ans;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                for(int k = 0; k < K; k++)
                    ans[i][k] += a[i][j] * x[j][k];
        return ans;
    }
    Matrix operator*(T x) const {
        Matrix ans = *this;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                ans[i][j] *= x;
        return ans;
    }
    Matrix& operator*=(T x) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] *= x;
        return *this;
    }
    
    template<typename K>
    Matrix operator^(K x) const {
        assert(x >= 0);
        Matrix res(1), A = *this; while(x) {
            if(x & 1) res = res * A;
            x >>= 1; A = A * A;
        } return res;
    }
};
// Matrix<int64_t, 3, 4> M = {{1, 2, 3, 4}, {-1, 234, 2, 45}, {1, 241, 65, 69}};

// -----------------------------------------------------------------
// vector implementation for non-compile time size matrix (slower)
template<typename T>
struct Matrix {
    int N, M; vector<vector<T>> a;
    
    Matrix(int n, int m): N(n), M(m) , a(n, vector<T>(m)) {}
    explicit Matrix(int n, int m, T x): Matrix(n, m) {
        for(int i = 0; i < min(N, M); i++) a[i][i] = x;
    }
    Matrix(initializer_list<vector<T>> x) {
        N = x.size(); M = x.begin()->size(); a.resize(N);
        for(int i = 0; i < sz(x); i++)
            a[i] = *(x.begin() + i), assert(sz(a[i]) == M);
    }
    
    vector<T>& operator[](int x) { return a[x]; }
    const vector<T>& operator[](int x) const { return a[x]; }
    friend ostream& operator<<(std::ostream& out, const Matrix& x) {
        for(int i = 0; i < x.N; i++) 
            for(int j = 0; j < x.M; j++) 
                out << x.a[i][j] << " \n"[j == x.M-1];
        return out;
    }

    Matrix& operator+=(const Matrix& x) {
        assert(N == x.N and M == x.M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] += x[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& x) {
        assert(N == x.N and M == x.M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] -= x[i][j];
        return *this;
    }

    Matrix operator+(const Matrix& x) const {
        Matrix ans = *this;
        return ans += x;
    }
    Matrix operator-(const Matrix& x) const {
        Matrix ans = *this;
        return ans -= x;
    }

    Matrix operator*(const Matrix& x) const {
        Matrix<T> ans(N, x.M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                for(int k = 0; k < x.M; k++)
                    ans[i][k] += a[i][j] * x[j][k];
        return ans;
    }
    Matrix& operator*=(T x) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] *= x;
        return *this;
    }
    Matrix operator*(T x) const {
        Matrix ans = *this;
        return ans *= x;
    }

    template<typename K>
    Matrix operator^(K x) const {
        assert(x >= 0);
        Matrix res{N, M, 1}, A = *this; while(x) {
            if(x & 1) res = res * A;
            x >>= 1; A = A * A;
        } return res;
    }
};
