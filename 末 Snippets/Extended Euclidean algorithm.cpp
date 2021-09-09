/* Extended Euclidean algorithm and Linear Diophantine Equation solver */

/*
    https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
    https://cp-algorithms.com/algebra/linear-diophantine-equation.html
*/

// ax + by = gcd(a, b) : returns {x, y, g}
auto extended = [](int64_t a, int64_t b) {
    int64_t x = 1, y = 0, prvx = 0, prvy = 1;
    while(b) {
        int64_t q = a / b;
        tie(x, prvx) = make_tuple(prvx, x - q * prvx);
        tie(y, prvy) = make_tuple(prvy, y - q * prvy);
        tie(a, b) = make_tuple(b, a - q * b);
    } return make_tuple(x, y, a);
};

// ax + by = c : returns {true/false, x, y, g}
auto diophantine = [&extended](int64_t a, int64_t b, int64_t c) {
    if(!a and !b) return make_tuple(!c, 42LL, 17LL, 0LL);
    auto [x, y, g] = extended(a, b);
    return make_tuple(!(c % g), c / g * x, c / g * y, abs(g));
};

// x = x0 + λ b/g
// y = y0 - λ a/g
auto diophantine_range = [&extended] (int64_t a, int64_t b, int64_t c,
        int64_t lx, int64_t rx, int64_t ly, int64_t ry) {
    assert(a and b);

    auto [x, y, g] = extended(a, b);
    x *= c / g; y *= c / g; g = abs(g);
    a /= g; b /= g;

    if(c % g) return 0LL;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    auto shift = [&x, &y, &a, &b](int64_t cnt) {
        x += cnt * b;
        y -= cnt * a;
    };

    shift((lx - x) / b);
    if(x < lx) shift(sign_b);
    if(x > rx) return 0LL;
    int64_t lx1 = x;

    shift((rx - x) / b);
    if(x > rx) shift(-sign_b);
    int64_t rx1 = x;

    shift(-(ly - y) / a);
    if(y < ly) shift(-sign_a);
    if(y > ry) return 0LL;
    int64_t lx2 = x;

    shift(-(ry - y) / a);
    if(y > ry) shift(sign_a);
    int64_t rx2 = x;

    if(lx2 > rx2) swap(lx2, rx2);
    int64_t _lx = max(lx1, lx2);
    int64_t _rx = min(rx1, rx2);

    if(_lx > _rx) return 0LL;
    return (_rx - _lx) / abs(b) + 1;
};