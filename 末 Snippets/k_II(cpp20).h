/* Debugging artillery */

/*
    C++20 concepts <3
*/

#include <bits/stdc++.h>

#define sep ", "
#define tr(...) cout << "(" << __LINE__ << ")["#__VA_ARGS__ "]:[", pr(__VA_ARGS__), cout << "]\n"
#define tra(arg, args...) ptrace(#arg, arg, args)

namespace concepts {
    template <typename T>
    concept is_readable = requires(T x) {
        std::cin >> x;
    };

    template <typename T>
    concept is_writable = requires(T x) {
        std::cout << x;
    };

    template <typename T>
    concept is_iterable = requires(T x) {
        x.begin(); x.end();
    };

    template <typename T>
    concept is_tuple_like = requires(T x) {
        typename std::tuple_size<T>::type;
    };
}

namespace reading {
    template <concepts::is_readable T> void re(T& t) { std::cin >> t; }
    template <typename T> requires(concepts::is_iterable<T> && !concepts::is_readable<T>)
    void re(T& t) { for(auto& x: t) re(x); }
    template <typename T> requires(concepts::is_tuple_like<T> && !concepts::is_readable<T>)
    void re(T& t) { apply([&](auto&... args) { (re(args), ...); }, t); }
    template <class... Ts> void re(Ts&... ts) { (re(ts), ...); }
}

namespace writing {
    template <concepts::is_writable T> void pr(const T& t) { std::cout << t; }

    template <typename T> requires(concepts::is_iterable<T> && !concepts::is_writable<T>)
    void pr(const T& t) {
        std::cout << '{';
        for(bool fst = true; const auto& x: t)
            std::cout << (fst? fst = false, "" : sep), pr(x);
        std::cout << '}';
    }

    template <typename T> requires(concepts::is_tuple_like<T> && !concepts::is_writable<T>)
    void pr(const T& t) {
        std::cout << '(';
        apply([&](const auto&... args) {
            bool fst = true;
            ((fst ? (fst = false, pr(args)) : (std::cout << sep, pr(args))), ...);
        }, t);
        std::cout << ')';
    }

    template <class T, class... Ts>
    void pr(const T& t, const Ts&... ts) {
        pr(t), ((std::cout << sep, pr(ts)), ...);
    }

    template <class... Ts>
    void ps(const Ts&... ts) {
        pr(ts...), std::cout << std::endl;
    }

    template <class... Ts>
    void pw(Ts&&... ts) {
        pr(ts...), std::cout << ' ';
    }

    template <class T, class... Ts>
    void ptrace(const char *name, const T& A, const Ts&... rest) {
        const char *open = strchr(name, '[');
        std::cout.write(name, open - name);
        ((std::cout << '[' << rest << ']'), ...);
        std::cout << " = ", ps(A);
    }
}

template <size_t U>
using bs = std::bitset<U>;

using namespace reading;
using namespace writing;