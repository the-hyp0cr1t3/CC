/* directly from code */
// https://codeforces.com/blog/entry/94726?#comment-839042

void main_() {
    int i, n;
    cin >> n;

}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}

int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024);     // 1 GB
    return 0;
}

/* via command line */
// Windows
// g++ -Wl,-stack=268435456 -std=c++17 file.cpp -o file

// Linux
// ulimit -s unlimited && g++ -std=c++17 file.cpp -o file
