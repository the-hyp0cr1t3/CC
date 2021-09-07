/* Binary Search */

/*
    https://github.com/the-hyp0cr1t3/CC/blob/master/Beginner%20Topics/%5BS3%5D%202P%20or%20not%20to%202P%2C%20No%20wait%20isn%27t%20this%20just%20bs/%5BEP%203%5D%20Binary%20search.md
*/

auto check = [&](int x) {
    // ...
    return true;
};

auto binarySearch = [&](int low, int high) {
    while(low <= high) {
        int mid = low + high >> 1;
        if(check(mid)) low = mid + 1;       // Assuming TT...TFF...F
        else high = mid - 1;
    } return high; // return low for first occurrence of False, high for last occurrence of True
};

