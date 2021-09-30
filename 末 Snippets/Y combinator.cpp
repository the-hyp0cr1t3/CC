/* Y combinator - facilitate recursion in lambdas */

/*
    Inspired by [ecnerwala](https://codeforces.com/profile/ecnerwala)
    Read more from [here](https://mvanier.livejournal.com/2897.html)
*/

using namespace std;
template<class T> class Y {
    T f_;
public:
    template<class U> explicit Y(U&& f): f_(forward<U>(f)) {}
    template<class ...Args> decltype(auto) operator()(Args&&... args) {
        return f_(ref(*this), forward<Args>(args)...);
    }
};  template<class T> Y(T) -> Y<T>; // template deduction guide (C++17)

//For C++14 and before, refer to [submission](https://codeforces.com/contest/1466/submission/102864010)

auto factorial = Y([&](auto self, int n) -> int {
    return n == 0? 1 : n * self(n-1);
});

std::cout << factorial(5);
