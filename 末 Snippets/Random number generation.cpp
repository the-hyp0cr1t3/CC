namespace randnum {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    // random int or ll in [L, R]
    template<typename T>
    T randint(T L, T R) {
        uniform_int_distribution<T> d(L, R);
        return d(rng);
    }

    // random int or ll in [0, n)
    template<typename T>
    T randint(T n) {
        return randint(T(0), T(n-1));
    }

    // random array of size n
    // each element in [L, R]
    template<typename T>
    vector<T> randarr(T n, T L, T R) {
        vector<T> v(n);
        for(auto& x: v) 
            x = randint(L, R);
        return v;
    }

    // random string of length n
    // each element in charset
    template<typename T>
    string randstr(T n, string charset = "abcdefghijklmnopqrstuvwxyz") {
        int w = charset.size();
        string res;
        for(int i = 0; i < n; i++) 
            res += charset[randint(w)];
        return res;
    }

    // random shuffle a vect
    template<typename T>
    void shuffle(vector<T>& v) {
        shuffle(v.begin(), v.end(), rng);
    }

/* weighted random in range [0, n-1] */
    // from "testlib.h"
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

/* Random tree generator (0-indexed) */
    // from "testlib.h"
    // (Based on Prufer code)
    // n -> number of nodes
    // elongation -> [-value, +value]
    // More +ve => less branching
    // More -ve => more branching
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
            edges.emplace_back(u, v);
        }

        shuffle(edges);
        return edges;
    }
}

