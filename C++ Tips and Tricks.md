# C++ Tips and Tricks

Here are some neat tricks I've come across through my experience with CP and C++ in general. The inspiration to write this came from [here](https://codeforces.com/blog/entry/74684).
 
### Global variable initialization
Globally declared variables are, by default, initialized to 0 at compile time (see [this](https://www.tutorialspoint.com/why-are-global-and-static-variables-initialized-to-their-default-values-in-c-cplusplus)). Initializing them is redundant.

### Typecasting

### sz(x)
The ```size()``` method, compatible with most STL containers, returns a value of type ```size_t```, which is an *unsigned int*. When comparisons are made between values of different data types, the compiler (implicitly) typecasts one of them to the other. When a negative integer of type ```int``` is casted to an ```unsigned int```, the expression may evaluate to a different value altogether. So you'd have to explicitly typecast ```size()``` to int every time. To do this, you may find the following macro useful.
```c++
#define sz(x) (int)x.size()

// using it
vector<int> v{1, 2, 3};
int x = sz(v);
```

#### Use 1LL or 1ll
When you are handling arithmetic expressions which may overflow ```int```, you have to typecast it to ```long long```. A simpler way of doing that is:
```c++
int x = 1e9;
long long a = x * x;
long long b = (long long) x * x;
long long c = 1ll * x * x;
cout << a << endl << b << endl << c;
```
**Output**
```
-1486618624
1000000000000000000
1000000000000000000
```
Same thing can be done with *1.0* for ```double```.

### Bitwise operators and more

The **Bitwise One's Complement** operator,  ```~```,  is a unary operator which flips the bits. How is this useful? It returns a non-zero value for all numbers except -1.
```c++
// iterating in reverse, while i >= 0
for(int i = n-1; ~i; i--) 
    // do stuff
```

The **Bitwise AND** operator, ```&```, only sets bits which are common to either operand. It can be used to check parity of an integer.
```c++
int n = 42;
if(n & 1) cout << "odd";
if(~n & 1) cout << "even";
```

The **Bitwise XOR** operator, ```^```, only sets bits which are exclusive to either operand. It evaluates to 0 if both operands are equal.
```c++
void dfs(int u, int par) {
   for(auto v: graph[u])
       if(v ^ p) dfs(v, u);
}
```

The **Logical NOT** operator, when used on itself, ```!!```, is equivalent to typecasting the operand to bool, i.e, it returns false if the value is 0, and true if the value is anything else.
```c++
for(int i = 0; i < n; i++)
    cnt_nonzeros += !!arr[i];
```

Add two ints and divide by two without overflow or underflow (usecases such as binary search):
```c++
int L = 2e9, R = 2e9+2;
int mid = (L + R) / 2;          // -147483647 overflow
int mid = (L&R) + ((L^R)>>1);   // 2000000001 nice

int mid = (-L + -R) / 2;                  // 147483647 underflow
int mid = (-L & -R) + ((-L ^ -R) >> 1);   // -2000000001 nice
```

Fast min and max
```c++
#define max(x, y) (y-x >> 31 & (x^y) ^ y)
#define min(x, y) (y-x >> 31 & (x^y) ^ x)
// Ensure that y-x does not overflow or underflow
```

Iterate only over n-bit bitmasks with exactly k bits set ([Credit](https://codeforces.com/blog/entry/17881?#comment-227737)):
```c++
for(int msk = (1<<k)-1; msk < 1<<n;) {
    // ...
    if(!msk) break;
    int x = msk & -msk, y = msk + x;
    msk = (msk & ~y) / x >> 1 | y;
}
```

### A more convenient if statement
Consider a scenario where you are calling some function ```f()```. If its value satisfies some condition ```ok()```, you want use it.
```c++
if (ok(f())) {
    use(f());
}
```
This costs 2 function calls, which may be inefficient. What one would normally do then, is:
```c++
int x = f();
if (ok(x)) {
    use(x);
}
```
However, this is also not very clean and leaves a variable which is not used.
The following is a concise way of doing the same thing (valid C++17 onwards).
```c++
if (int x = f(); ok(x)) {
    use(x);
}
```

### Check if a string is a palindrome
```c++
inline bool isPalindrome(const string& s) {
    return std::equal(s.begin(), s.end(), s.rbegin());
}
```

### Auto type-deduction, Range-based for loops and Structured bindings
The magic word [auto](https://www.tutorialspoint.com/What-does-an-auto-keyword-do-in-Cplusplus) (introduced as a deduced type in C++11), behaves like a placeholder type specifier.
```c++
vector<int> v{1, 2, 3};

// how you would normally do it
vector<int>::iterator it = find(all(vect), 2);

// much simpler
auto it = find(v.begin(), v.end(), 2);
```

C++11 also introduces range based for loops which make code easier to implement and more readable.
```c++
for(int i = 0; i < vect.size(); i++)
    // do stuff with vect[i]
for(auto x: vect)
    // do stuff with x
```

Structured binding, a utility of C++17, allows a single definition to define multiple variables with different types simultaneously.
```c++
pair<int, int> p = make_pair(2, 3);
auto [f, s] = p;
cout << f << s;

map<int, string> mp;
for(auto [key, value]: mp) {
   cout << key << value;
}
```
A nifty trick to simultaneously check if a value exists in a set, and insert it otherwise, is to:
```c++
set<int> s;
auto [itr, isInserted] = s.insert(2);
if(isInserted)
   cout << *it;
else
   cout << "is already present";
```

### Lambdas
A lambda is an expression that generates a function object (a functor) on the fly. Lambdas allow you to inline anonymous function objects as parameters to various STL functions. They can also capture (or close over) variables from the surrounding scope, either by value or by reference.

[Good article on Lambdas](https://blog.feabhas.com/2014/03/demystifying-c-lambdas/)

[Documentation](https://en.cppreference.com/w/cpp/language/lambda)

In the context of cp, I find lambdas quite useful for its following aspects
* Anonymous inlining of functors that act as *comparators* for various STL functions like ```sort()```.
* Function-like behaviour and capture of local variables to perform repetitive tasks, without having to explicitly pass as many arguements.

```c++
vector<pair<int, int>> v{{1, 2}, {3, -5}, {-1, 0}};

// sorting by second value of pair using a lambda as comparator
auto cmp = [](const pair<int, int>& A, const pair<int, int>& B) { 
    if(A.second == B.second) return A.first < B.first;
    return A.second < B.second; 
});
sort(all(v), cmp);

// sorting by second value of pair using a lambda (inline) as comparator
sort(all(v), [](const pair<int, int>& A, const pair<int, int>& B) { 
    if(A.second == B.second) return A.first < B.first;
    return A.second < B.second; 
});

#define x first
#define y second

auto dist = [&] (int a, int b) {     // the [] is the capture clause; Here [&] captures everything by reference.
    return sqrt((v[a].x-v[b].x)*(v[a].x-v[b].x) + (v[a].y-v[b].y)*(v[a].y-v[b].y));
};

for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) 
        cout << dist(i, j) << endl;     // calling it like a function
```

### Vector, Set and Map utility functions
Before we get to those lets introduce the following macro, as it will be used a couple of times further down.

#### all(x)
Many times you will find the need to pass ```x.begin(), x.end()``` to STL functions, where x is an STL container. In that case, you may find the following macro useful.
```c++
#define all(x) (x).begin(), (x).end()
```

#### std::fill and std::iota
```std::fill``` fills an array or a vector with the specified value.
```c++
fill(arr, arr+n, 42);
fill(all(vect), 42);
```
```std::iota``` fills with consecutive numbers.
```c++
Dsu(int _n): n(_n), parent(_n), rank(_n) {
    iota(all(parent), 0);
}
```
Here 0 denotes the value of *\*parent.begin()*, and each next value is obtained from the previous one by incrementing it.

#### std::unique
Simple way of eliminating all duplicates in a vector is to make use of ```std::unique```.
```c++
sort(all(vect));
vect.erase(unique(all(vect)), vect.end());
```

#### std::rotate
```std::rotate``` cyclically shifts a vector to the left or right.
```c++
rotate(vect.begin(), vect.begin() + k, vect.end());
```
This function works in such a way that after rotate(begin, middle, end) the element *\*middle* becomes the first from beginning.

#### Sorting in reverse
```c++
sort(vect.begin(), vect.end());
reverse(vect.begin(), vect.end());
```
Instead,
```c++
sort(vect.rbegin(), vect.rend());
```

#### Min-max of multiple elements
You can rewrite this
```c++
int x = min(a, min(b, min(c, d)));
```
as
```c++
int x = min({a, b, c, d});
```

#### std::nth_element
```std:nth_element``` makes sure the nth element of the vector is at the nth position in linear time, if it was in sorted order. Note that it does not actually sort the vector. Here is an example.
```c++
vector<int> v{2, 4, 3, 1, 5, 6};
nth_element(v.begin(), v.begin()+3, v.end());
cout << v[3] << endl;
for(auto x: v)
    cout << x << " ";
```
**Output**
```
4
2 1 3 4 5 6
```

#### std::min_element and std::max_element
```std::min_element``` and ```std::max_element``` return an iterator to the min and max elements respectively.
```c++
vector<int> v{2, 4, 3, 1, 5, 6};
cout << *min_element(all(v));
cout << *max_element(all(v));
```

#### count()
To check if a key value exists within a set or map, use ```count()``` instead of ```find()```. It returns 1 if the element is present, 0 if not.
```c++
set<int> s;
if(s.count(42))
    // life has meaning
else
    // sad-face
```

### Optimizing vectors
The following is essentailly a summary of [this](https://www.youtube.com/watch?v=HcESuwmlHEY) video.

#### std::vector::reserve()
Capacity of a vector ([difference between size and capacity of a vector](https://stackoverflow.com/questions/6296945/size-vs-capacity-of-a-vector)) is the amount of space it is currently using. When the number of elements in the vector (aka its size) reaches its maximum capacity, it needs to be resized, or in the worst case, reallocated (which would take linear time as it invloves copying all the elements from one place to another). This is where the ```reserve()``` method comes in. If you roughly know before hand, the size of your vector, you can instruct the compiler to reserve enough space. It is not to be confused with ```resize()```; They do different things (see [reserve() vs resize()](https://stackoverflow.com/questions/13029299/stdvectorresize-vs-stdvectorreserve)).
```c++
vector<int> v;
v.reserve(N);
for(int i = 0; i < N; i++)
    v.push_back(i);
```

#### push_back() vs emplace_back()
The ```emplace_back()``` method essentially does everything ```push_back()``` does. In addition, it accepts constructor arguments and constructs the object directly within the vector, as opposed to ```push_back()```, which first has to create a temporary object, copy it to the vector, then destroy the temporary object. 
```c++
vector<pair<int, int>> v;
v.emplace_back(1, 2);

vector<pair<int, int>> graph[N];
for(int i = 0; i < m; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;
    graph[u].emplace_back(v, wt);
    graph[v].emplace_back(u, wt);
}
```
Read more about this from [here](http://candcplusplus.com/c-difference-between-emplace_back-and-push_back-function)

### assert()
The ```assert()``` macro is very useful in situations where you suspect something may be wrong. When an expression passed to ```assert()``` is false, it causes an abort and terminates the program (Runtime error). This is not only useful for local testing, but can be exploited on online judges such as codeforces. If an assertion is evaluated to be false in a particular test case, the judge returns an RTE verdict, so now you have an idea of what may be wrong.
```c++
int main() {
    // Do stuff, compute the answer. Lets store it in a variable ans
    // Now lets say that the final output is always supposed to be an integer greater than 1  
    assert(ans > 1);   // If ans <= 1 then you will see an RTE verdict, and thats how you know something is wrong with your logic above
    cout << ans;
    return;
}
```

### Bitsets
A bitset is a dataset that stores multiple boolean values but takes lesser memory space as compared to other data sets that can store a sequence of bits like a boolean array or boolean vector. One of the constructor overloads accepts and integer, which means, you can get the binary representation of an integer in as simple as 2 lines:
```c++
int n = 10;
bitset<32> b(n);
cout << b;
cout << b[i];    // accessing the i-th bit directly
cout << b.count();    // returns number of set bits
b ^= 1;      // bitwise operators also work
b &= 12;
b |= 3;
cout << b.to_ulong();   // returns the integer in decimal form
```

### Builtin functions of the GCC Compiler
Here are some not-so-widely known builtin functions to make life simpler.

#### __gcd()

As the name suggests, it finds the gcd of two integers.
```c++
int x = 4, y = 6;
cout << __gcd(x, y);   // returns 2.
```

#### __builtin_popcount()

To count the number of set bits, simply use ```__builtin_popcount()``` for 32-bit int and ```__builtin_popcountll()``` for 64-bit int.
```c++
int x = 5;
cout << __builtin_popcount(x);   // returns 2.
```

#### __builtin_clz(x) and __builtin_ctz(x)

To count the number of leading and trailing zeroes in binary representation, use ```__builtin_clz()``` and ```__builtin_ctz()``` for 32-bit int and ```__builtin_clzll()``` and ```__builtin_ctzll()``` for 64-bit int respectively.
```c++
int x = 10;    // 00000000 00000000 00000000 00001010 (32 bits)
cout << __builtin_clz(x);   // returns 28.
cout << __builtin_ctz(x);   // returns 1.

int x = 10;    // 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00001010 (64 bits)
cout << __builtin_clzll(x);   // returns 60.
cout << __builtin_ctzll(x);   // returns 1.
```

One particularly common use case is to find the greatest power of two which is less than or equal to a number, i.e its most significant bit. This can be done with `__builtin_clz`.
```c++
cout << 31 - __builtin_clz(n) << '\n';
cout << 63 - __builtin_clzll(n) << '\n';
```

#### __builtin_ffs() and __lg()

```__lg()``` returns the index of the highest set bit.

```__builtin_ffs()``` (Find first set) returns (the index of the least significant bit) + 1

```c++
int x = 10;    // 00000000 00000000 00000000 00001010 (32 bits)
cout << __lg(x);   // returns 3
cout << __builtin_ffs(x);   // returns (1+1) = 2
```

### Clocking
Here is a clean way of measuring execution time.

The timer is set to start when the object is instantiated (constructor is invoked). When the object falls out of scope (destructor is invoked) it returns the time elapsed since then.
```c++
using namespace std::chrono;
struct Timer {
    string name{""};
    time_point<high_resolution_clock> end, start{high_resolution_clock::now()};
    duration<float, std::milli> duration;
    Timer() = default;
    Timer(string name): name(name) {}
    ~Timer() {
        end = high_resolution_clock::now(); duration = end - start;
        cout << "@" << name << "> " << duration.count() << " ms" << '\n';
    }
};
```
Here is how you'd use it.
```c++
void func() {
    Timer timer2("Inside");
    this_thread::sleep_for(chrono::milliseconds(100));
}

int main() {
    Timer timer("Main");
    func();
    this_thread::sleep_for(chrono::milliseconds(230));
    return 0;
}
```

**Output**
```
@Inside> 109.2 ms
@Main> 343.201 ms
```
