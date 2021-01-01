// (https://cp-algorithms.com/algebra/binary-exp.html)
template<typename T>
T expo(T A, int64_t B) {        // A^{B}
    T res{1}; while(B) {
        if(B & 1) res = res * A;
        B >>= 1; A = A * A;
    } return res;
}
