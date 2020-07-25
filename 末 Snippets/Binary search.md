```c++
auto check = [&] (int x) {
    // ...
    return true;
};

auto binarySearch = [&] (int low, int high) {
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high; 
};

```