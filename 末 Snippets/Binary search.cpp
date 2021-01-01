/* Binary Search */

auto check = [&] (int x) {
    // ...
    return true;
};

auto binarySearch = [&] (int low, int high) {
    while(low <= high) {
        int mid = low + high >> 1;
        if(check(mid)) low = mid + 1;       // Assuming TT...TFF...F
        else high = mid - 1;
    } return high; // return low for first occurrence of False, high for last occurrence of True
};

