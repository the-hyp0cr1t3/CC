/* Random namespace */

namespace Randnum {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define EnableIntegral typename = enable_if_t<is_integral<T>::value>
    template<typename T = int, EnableIntegral>
    T randInt(int64_t L, int64_t R) {   // [L, R] inclusive
        uniform_int_distribution<T> d(L, R);
        return d(rng);
    }
    template<typename T = int, EnableIntegral>
    T randInt(int64_t n) {      // [0, n)
        return randInt<T>(0, n-1);
    }

    template<typename T = int, EnableIntegral>
    vector<T> randArray(int n, int64_t L, int64_t R) {
        vector<T> v(n);
        for(auto& x: v)
            x = randInt<T>(L, R);
        return v;
    }

    template<typename T>
    void shuffle(vector<T>& v) {
        shuffle(v.begin(), v.end(), rng);
    }

    const string binary = "01";
    const string digits = "0123456789";
    const string alpha = "abcdefghijklmnopqrstuvwxyz";
    const string alphanum = alpha + digits;

    string randString(int n, const string& charset = alpha) {
        string res; int len = charset.size();
        for(int i = 0; i < n; i++)
            res.push_back(charset[randInt(len)]);
        return res;
    }

/** Weighted random in range [0, n)
  * w_randInt(n, t) = max(randInt(n), randInt(n),... randInt(n)) ~--- t times
  * if t < 0, min is taken
  * magnitude is number of iterations **/
    template<typename T = int, EnableIntegral>
    T w_randInt(int64_t n, int type) {
        T result = randInt<T>(n);
        for(int i = 0; i < type; i++) {
            T nxt = randInt<T>(n);
            result = result < nxt? nxt : result;
        } for(int i = 0; i < -type; i++) {
            T nxt = randInt<T>(n);
            result = result > nxt? nxt : result;
        } return result;
    }

    enum InputFormat { Edges, Parents };

/** Random tree generator (1-indexed) **/
    template<InputFormat inp = Edges>
    auto randTree(int n, int elongation = 2e9) {
        if(elongation == 2e9)       // radomized if not passed as an arg
            elongation = randInt(1, n);    // +ve elong => rope-y, -ve elong => star-y

        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        shuffle(perm);          // shuffle(perm.begin()+1, perm.end(), rng) to root at 1

        vector<int> p(n);
        for(int i = 1; i < n; i++)
            p[i] = w_randInt(i, elongation);

        if constexpr(inp == Parents) { // ----- Parents ------
            vector<int> par(n, -1);
            for(int i = 1; i < n; i++)
                par[perm[i]] = perm[p[i]] + 1;
            return par;
        } else {                        // ----- Edges -------
            vector<pair<int, int>> edges; edges.reserve(n-1);
            for(int i = 1; i < n; i++)
                edges.push_back(randInt(2)?
                    make_pair(perm[i] + 1, perm[p[i]] + 1)
                    : make_pair(perm[p[i]] + 1, perm[i] + 1));
            return shuffle(edges), edges;
        }
    }

/** Random k-ary tree generator (1-indexed) **/
    // k = 1 for rope/chain, k = n-1 for star
    template<InputFormat inp = Edges>
    auto randTreeKary(int n, int k) {
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        shuffle(perm);

        if constexpr(inp == Parents) {  // ----- Parents -----
            vector<int> par(n, -1);
            for(int i = 0, j = 1; j < n; i++, j+=k)
                for(int id = j; id < min(n, j+k); id++)
                    par[perm[id]] = perm[i] + 1;
            return par;
        } else {                        // ----- Edges -------
            vector<pair<int, int>> edges; edges.reserve(n-1);
            for(int i = 0, j = 1; j < n; i++, j += k)
                for(int id = j; id < min(n, j+k); id++)
                    edges.push_back(randInt(2)?
                        make_pair(perm[i] + 1, perm[id] + 1)
                            : make_pair(perm[id] + 1, perm[i] + 1));
            return shuffle(edges), edges;
        }
    }

}

/*
int main() {
    using namespace Randnum;

    int n = randInt(2, 5);
    int64_t m = randInt<int64_t>(12345678901234567LL);
    string s = randString(n, alpha);

    vector<int64_t> vec = randArray<int64_t>(n, 0, 1ll<<62);
    shuffle(vec);

    vector<pair<int, int>> edges = randTree<Edges>(n);
    vector<int> parents = randTree<Parents>(n, -n/2);

    vector<pair<int, int>> karyedges = randTreeKary(n, randInt(1, n-1));
} // ~W 
*/
