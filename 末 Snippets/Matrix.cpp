// Inspired by [this](https://codeforces.com/contest/954/submission/41309586) submission by [LHiC](https://codeforces.com/profile/LHiC)
template<typename T>
struct Matrix {
    int N, M;
    vector<vector<T>> a;
    Matrix(int n, int m): N(n), M(m) {
        a = vector<vector<T>>(N, vector<T>(M));
    }
    explicit Matrix(int n, int m, T x): N(n), M(m) {
        a = vector<vector<T>>(N, vector<T>(M, 0));
        for(int i = 0; i < N and i < M; i++) a[i][i] = x;
    }
    Matrix(initializer_list<vector<T>> x) {
        N = x.size(); M = x.begin()->size(); a.resize(N);
        for(int i = 0; i < sz(x); i++)
            a[i] = *(x.begin() + i), assert(sz(a[i]) == M);
    }
    friend ostream& operator<<(std::ostream& out, const Matrix& x) {
        for(int i = 0; i < x.N; i++) 
            for(int j = 0; j < x.M; j++) 
                out << x.a[i][j] << " \n"[j == x.M-1];
        return out;
    }
    vector<T>& operator[](int x) { 
        return a[x]; 
    }
    const vector<T>& operator[](int x) const { 
        return a[x]; 
    }
    Matrix& operator+=(const Matrix& x) {
        assert(N == x.N and M == x.M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] += x[i][j];
        return *this;
    }
    Matrix operator+(const Matrix& x) {
        Matrix ans = *this;
        return ans += x;
    }
    Matrix& operator-=(const Matrix& x) {
        assert(N == x.N and M == x.M);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] -= x[i][j];
        return *this;
    }
    Matrix operator-(const Matrix& x) {
        Matrix ans = *this;
        return ans -= x;
    }
    Matrix operator*(const Matrix& x) {
        Matrix<T> ans(N, x.M);
        for(int i = 0; i < N; i++)
            for(int k = 0; k < x.M; k++)
                for(int j = 0; j < M; j++)
                    ans[i][k] += a[i][j] * x[j][k];
        return ans;
    }
    Matrix& operator*=(T x) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                a[i][j] *= x;
        return *this;
    }
    Matrix operator*(T x) {
        Matrix ans = *this;
        return ans *= x;
    }
    template<typename K>
    Matrix operator^(K x) {
        assert(x >= 0);
        Matrix res{N, M, 1}, A = *this; while(x) {
            if(x & 1) res = res * A;
            x >>= 1; A = A * A;
        } return res;
    }
};
