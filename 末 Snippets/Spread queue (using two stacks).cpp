/* Spread queue (using two stacks) */
// Calculate and maintain associative functions over a segment (pair with 2-pointer) in O(n)
// Eg: Find the number of segments of an array with gcd = 1 or max - min <= k

// T = val, e is the identity element (e ⊕ a = a ⊕ e = a)
// T f(T, T)
template<class T, T e, typename F>
class SpreadQueue {
    int size; T in; F f;
    stack<T> out, val_in, val_out;

public:
    template<typename G>
    SpreadQueue(G&& g): f(forward<G>(g)), size(0), in(e) { out.push(e); }

    void push(T v) {
        val_in.push(v); in = f(in, v); size++;
    }

    void pop() {
        if(val_out.empty()) {
            while(!val_in.empty()) {
                val_out.push(val_in.top()); val_in.pop();
                out.push(f(val_out.top(), out.top()));
            } in = e;
        } out.pop(); val_out.pop(); assert(size--);
    }

    T best() const {
        return empty()? e : f(in, out.top());
    }

    bool empty() const { return !size; }
};

// make
template<class T, T e, typename F>
auto make_SpreadQueue(F&& f) {
    return SpreadQueue<T, e, decltype(f)> (forward<F>(f));
}

int main() {

    // gcd spread eg
    auto q = make_SpreadQueue<int64_t, 0>([](auto x, auto y) { return gcd(x, y); });

    // min and max spread
    auto mnq = make_SpreadQueue<int64_t, INF>(
                [](auto x, auto y) { return min(x, y); });
    auto mxq = make_SpreadQueue<int64_t, -INF>(
                [](auto x, auto y) { return max(x, y); });

}


/*
    Resource: https://codeforces.com/edu/course/2/lesson/9/2

    Gcd: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G
    http://p.ip.fi/ow-L

    Min-max: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F
    http://p.ip.fi/GWT_
*/