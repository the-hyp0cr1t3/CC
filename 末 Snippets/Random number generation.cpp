namespace randnum {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    // random int in [L, R]
    template<typename T>
    T randint(T L, T R) {
        uniform_int_distribution<T> d(L, R);
        return d(rng);
    }

    // random int in [0, n-1]
    template<typename T>
    T randint(T _n) {
        return randint(T(0), T(_n-1));
    }

    // random array of size N
    // each element in [L, R]
    template<typename T>
    vector<T> randarr(T _n, T L, T R) {
        vector<T> v(_n);
        for(auto& x: v) 
            x = randint(L, R);
        return v;
    }

    // random string of length N
    // each element in charset
    template<typename T>
    string randstr(T _n, const string charset = "abcdefghijklmnopqrstuvwxyz") {
        int _w = charset.size();
        string res;
        for(int i = 0; i < _n; i++) 
            res += charset[randint(_w)];
        return res;
    }

    // random shuffle a vect
    template<typename T>
    void shuffle(vector<T>& v) {
        shuffle(v.begin(), v.end(), rng);
    }

    // weighted random in range [0, n-1]
    // w_rand(n, t) = max(rand(n), rand(n), ...rand(n)) ~--- t times
    // if t < 0, min is taken
    // type specifies number of iterations
    template<typename T>
    T w_rand(T n, T type) {
        T result = randint(n);
        for(T i = 0; i < type; i++) {
            T nxt = randint(n);
            result = result < nxt? nxt : result;
        }
        for(T i = 0; i < -type; i++) {
            T nxt = randint(n);
            result = result > nxt? nxt : result;
        }
        return result;
    }

    // Random tree generator (0-indexed)
    // (Based on Prufer code)
    // n -> number of nodes
/* --------  value 1000 is to yet to be tested as bounds ----- */
    // elongation -> [-1000, +1000]
    // +1000 => degree at most 2
    // -1000 => star graph
    vector<pair<int, int>> gen_tree(int n, int elongation) {
        // gen parents, 0 is root
        vector<int> par(n);
        for(int i = 1; i < n; i++) 
            par[i] = w_rand(i, elongation);

        // gen permuation (shuffling of labels)
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        shuffle(perm.begin()+1, perm.end(), rng);

        // insert each (i, par[i]) pair with respective labels
        vector<pair<int, int>> edges;
        edges.reserve(n-1);
        for(int i = 1; i < n; i++) {
            int u = perm[i]; int v = perm[par[i]];
            if(randint(2)) swap(u, v);
            edges.emplace_back(u+1, v+1);
        }

        shuffle(edges);
        return edges;
    }
} using namespace randnum;
