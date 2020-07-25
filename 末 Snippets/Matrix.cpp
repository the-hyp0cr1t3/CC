// Inspired by [this](https://codeforces.com/contest/954/submission/41309586) submission by [LHiC](https://codeforces.com/profile/LHiC)

template<typename T, int N, int M = N>
struct Matrix {
    array<T, M> a[N];
    Matrix() {
        for(int i = 0; i < N; i++) 
            a[i].fill(T());
    }
    explicit Matrix(T x) {
        for(int i = 0; i < N; i++) 
            a[i].fill(T());
        for(int i = 0; i < N and i < M; i++)
            a[i][i] = x;
    }
    Matrix(initializer_list<array<T, M>> x) {
        assert(x.size() <= N);
        for(int i = 0; i < x.size(); i++)
            a[i] = *(x.begin() + i);
        for(int i = x.size(); i < N; i++)
            a[i].fill(0);
    }
    friend ostream& operator<<(std::ostream& out, const Matrix& x) {
        for(int i = 0; i < N; i++) 
            for(int j = 0; j < M; j++) 
                out << x.a[i][j] << " \n"[j == M-1];
        return out;
    }
    array<T, M>& operator[](int x) { return a[x]; }
    const array<T, M>& operator[](int x) const { return a[x]; }
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
    Matrix operator+(const Matrix& x) {
        Matrix ans = *this;
        return ans += x;
    }
    Matrix operator-(const Matrix& x) {
        Matrix ans = *this;
        return ans -= x;
    }
    template<int K>
    Matrix<T, N, K> operator*(const Matrix<T, M, K>& x) {
        Matrix<T, N, K> ans;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                for(int k = 0; k < K; k++)
                    ans[i][k] += a[i][j] * x[j][k];
        return ans;
    }
    Matrix operator*(T x) {
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
    Matrix operator^(K x) {
        assert(x >= 0);
        Matrix res(1), A = *this; while(x) {
            if(x & 1) res = res * A;
            x >>= 1; A = A * A;
        } return res;
    }
};
