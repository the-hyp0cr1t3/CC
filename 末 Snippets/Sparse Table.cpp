const int K = 22;
int a[N];

struct sparse {
    int kmax, n, table[K][N], idx[K][N];
    function<int(int, int)> cmp;

    sparse(function<int(int, int)> f): cmp(f) {}

    int _log(int x) {
        return 31 - __builtin_clz(x);
    }

    void build(int nn) {
        kmax = _log(nn);
        for(int i = 0; i < nn; i++) {
            table[0][i] = a[i];
            idx[0][i] = i;
        }
        
        for(int k = 1; k <= kmax; k++) {
            for(int i = 0; i+(1<<k) <= nn; i++) {
                if(cmp(table[k-1][i], table[k-1][i+(1<<(k-1))])) {
                    table[k][i] = table[k-1][i];
                    idx[k][i] = idx[k-1][i];
                }
                else {
                    table[k][i] = table[k-1][i+(1<<(k-1))];
                    idx[k][i] = idx[k-1][i+(1<<(k-1))];
                }
            }
        }
    }

    int query(int l, int r) {
        int k = _log(r-l+1);
        r = r-(1<<k)+1;
        return cmp(table[k][l], table[k][r])? idx[k][l] : idx[k][r];
    }
};

