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
    std::chrono::duration<float, milli> duration;
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
When you are handling arithmetic expressions which may overlow ```int```, you have to typecast it to ```long long```. A simple way of doing that is:
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
int a = 3, b = 0;
cout << bool(a) << " " << !!a << endl;
cout << bool(b) << " " << !!b << endl;
```
**Output**
```
1 1
0 0
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

### Auto type-deduction, Range-based for loops and Structured bindings
The magic word [auto](https://www.tutorialspoint.com/What-does-an-auto-keyword-do-in-Cplusplus) (introduced as a deduced type in C++11), behaves like a placeholder type specifier.
```c++
vector<int> v{1, 2, 3};

// how you would normally do it
vector<int>::iterator it = find(v.begin(), v.end(), 2);

// much simpler
auto it = find(v.begin(), v.end(), 2);
```

C++11 also introduces range based for loops which make code easier to implement and more readable.
```c++
for(int i = 0; i < vect.size(); i++)
    // do stuff with vect[i]
for(auto it: vect)
    // do stuff with *it
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
