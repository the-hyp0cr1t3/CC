// Inspired by [ecnerwala](https://codeforces.com/profile/ecnerwala)
template<class T> class Y {
    T f_;
public:
    template<class U> explicit Y(U&& f): f_(forward<U>(f)) {}
    template<class ...Args> decltype(auto) operator()(Args&&... args) {
        return f_(ref(*this), forward<Args>(args)...);
    }
}; 
template<class T> Y(T) -> Y<T>;


auto recur = Y([&](auto self, auto&&... params) -> void {
    // ...
    self(params);
});

