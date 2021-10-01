/* Debugging artillery */

/*
    Insired by [Narut](https://codeforces.com/profile/narut)
*/

#include <bits/stdc++.h>
using namespace std;

constexpr bool loc = true;

#define tr(...) cout << "(" << __LINE__ << ")["#__VA_ARGS__ "]:[", pr(__VA_ARGS__), cout << "]\n"
#define tra(arg, args...) ptrace(#arg, arg, args)
#define SFINAE(x, ...) template < class, class = void > struct x: false_type {}; \
                       template < class T > struct x <T, void_t<__VA_ARGS__>>: true_type {};

SFINAE(DefaultIO, decltype(cout << declval<T&>()))
SFINAE(IsTuple, typename tuple_size<T>::type)
SFINAE(Iterable, decltype(begin(declval<T>())))

auto isLOC = [](auto A, string B = "") {
    return loc ? A : B;
};

template < class T > constexpr void re(T& t) {
    if constexpr(DefaultIO<T>::value) cin >> t;
    else if constexpr(Iterable<T>::value) for(auto& x: t) re(x);
    else if constexpr(IsTuple<T>::value) apply([&](auto&... args) { (re(args), ...); }, t);
    else static_assert(DefaultIO<T>::value, "No read type");
}

template < typename T > constexpr void re(T *beg, T *end) {
    for(T *it = beg; it != end; ++it) cin >> *it;
}

template < class... Ts > constexpr void re(Ts&... ts) {
    (re(ts), ...);
}

template < class T > constexpr void space(T) {
    if constexpr(DefaultIO<T>::value) cout << isLOC(", ", " ");
    else cout << isLOC(",") << endl;
}

constexpr void pr() {}
template < class T > constexpr void pr(const T& t) {
    if constexpr(DefaultIO<T>::value) cout << t;
    else if constexpr(Iterable<T>::value) {
        cout << isLOC("{");
        bool fst = 1;
        for(auto&& x: t) {
            if(fst) fst = 0;
            else space(x);
            pr(x);
        }
        cout << isLOC("}");
    } else if constexpr(IsTuple<T>::value) {
        cout << isLOC("(");
        apply([&](const auto&... args) {
            bool fst = 1;
            ((fst ? (fst = 0, pr(args)) : (space(args), pr(args))), ...);
        }, t);
        cout << isLOC(")");
    } else static_assert(DefaultIO<T>::value, "No write type");
}

template < typename T > constexpr void pr(T *beg, T *end) {
    cout << isLOC("{");
    for(T *it = beg; it != end; ++it) {
        if(it != beg) space(*it);
        pr(*it);
    }
    cout << isLOC("}");
}

template < class T, class... Ts > constexpr void pr(const T& t, const Ts&... ts) {
    pr(t), ((space(ts), pr(ts)), ...);
}

template < class... Ts > constexpr void ps(Ts&&... ts) {
    pr(ts...);
    cout << endl;
}

template < class... Ts > constexpr void pw(Ts&&... ts) {
    pr(ts...);
    cout << ' ';
}

template < class T, class... Ts > constexpr void ptrace(const char *name, T&& A, Ts&&... rest) {
    const char *open = strchr(name, '[');
    cout.write(name, open - name);
    ((cout << '[' << rest << ']'), ...);
    cout << " = ";
    ps(A);
}

template <size_t U>
using bs = bitset<U>;