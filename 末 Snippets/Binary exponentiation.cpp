template<typename T>
T expo(T A, ll B) {
    T res{1}; while(B) {
        if(B & 1) res = res * A;
        B >>= 1; A = A * A;
    } return res;
}
