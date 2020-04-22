Here are some neat tricks I've come across through my experience with CP and C++ in general.

### Pass by reference (Obligatory starter to list)
 Pass by ***[reference](https://pasteboard.co/J4IxG77.jpg)*** when possible and avoid passing by value; It improves performance.
 
### No need to initialize global variables
Globally declared variables are initialized to 0 at compile time (see [this](https://www.tutorialspoint.com/why-are-global-and-static-variables-initialized-to-their-default-values-in-c-cplusplus)). Initializing them is redundant.

### Measuring execution time
The timer is set to start when the object is instantiated (constructor is invoked). When the object falls out of scope (destructor is invoked) it returns the time elapsed since then.
```c++
struct Timer {
    string label = "";
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float, std::milli> duration;
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }
    Timer(string name) {
      label = name;
      start = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "@" << label << "> " << duration.count() << " ms" << '\n';
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

### Use 1LL or 1ll
When you are handling arithmetic expressions which may overlow ```int```, you have to typecast it to ```long long```. A simpler way of doing that is:
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

### !!, ~ and ^
The ```!!``` operator is equivalent to typecasting the operand to bool, i.e, it returns false if the value is 0, and true if the value is anything else.
```c++
for(int i = 0; i < n; i++)
    cnt_nonzeros += !!arr[i];
```

The ```~``` operator returns 0 if the value is -1.
```c++
// iterating in reverse, while i >= 0
for(int i = n-1; ~i; i--) 
    // do stuff
```

The ```^``` operator returns 0 if both operands are equal.
```c++
void dfs(int u, int par) {
   for(auto v: graph[u])
       if(v ^ p) dfs(v, u);
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

### Checking if a set or map has a key
Use ```count()``` instead of ```find()```. It returns 1 if the element is present, 0 if not.
```c++
set<int> s;
if(s.count(42))
    // life has meaning
else
    // sad-face
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
auto [itr, isPresent] = s.insert(2);
if(isPresent)
   cout << *it;
else
   cout << "is already present";
```

### all(x)
Many times you will find the need to pass ```x.begin(), x.end()``` to STL functions, where x is an STL container. In that case, you may find the following macro useful.
```c++
#define all(x) (x).begin(), (x).end()
```

### Sorting in reverse
```c++
sort(vect.begin(), vect.end());
reverse(vect.begin(), vect.end());
```
Instead,
```c++
sort(vect.end(), vect.begin());
```

### std::fill and std::iota
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

### std::unique
Simple way of eliminating all duplicates in a vector is to make use of ```std::unique```.
```c++
sort(all(vect));
vect.erase(unique(all(vect)), vect.end());
```

### std::rotate
```std::rotate``` cyclically shifts a vector to the left or right.
```c++
rotate(vect.begin(), vect.begin() + k, vect.end());
```
This function works in such a way that after rotate(begin, middle, end) the element *\*middle* becomes the first from beginning.

### Min-max of multiple elements
You can rewrite this
```c++
int x = min(a, min(b, min(c, d)));
```
as
```c++
int x = min({a, b, c, d});
```

### std::nth_element, std::min_element, std::max_element
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

```std::min_element``` and ```std::max_element``` return an iterator to the min and max elements respectively.
```c++
vector<int> v{2, 4, 3, 1, 5, 6};
cout << *min_element(all(v));
cout << *max_element(all(v));
```

### push_back() vs emplace_back()
```emplace_back()``` essentially does everything ```push_back()``` does. In addition, it accepts constructor arguments and constructs the object directly within the vector, as opposed to ```push_back()```, which first has to create a temporary object, copy it to the vector, then destroy the temporary object. It is thus more efficient. 
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
