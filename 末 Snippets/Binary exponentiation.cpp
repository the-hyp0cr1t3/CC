/* Binary Exponentiation */

/*
    https://github.com/the-hyp0cr1t3/CC/blob/master/Beginner%20Topics/%5BS2%5D%20Primal%20proficiency/%5BEP%205%5D%20Binary%20Exponentiation.md
*/

template<typename T>
T expo(T A, int64_t B) {        // A^{B}
    T res{1}; while(B) {
        if(B & 1) res = res * A;
        B >>= 1; A = A * A;
    } return res;
}
