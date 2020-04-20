Here are some neat tricks I've come across through my experience with CP and C++ in general.

## Pass by reference (Obligatory starter to list)
 Pass by [reference](https://pasteboard.co/J4IxG77.jpg) when possible and avoid passing by value; It improves performance.
 
## No need to initialize global variables
Globally declared variables are initialized to 0 at compile time (see [this](https://www.tutorialspoint.com/why-are-global-and-static-variables-initialized-to-their-default-values-in-c-cplusplus)). Initializing them is redundant.

## Measuring execution time
The timer is set to start when the object is instantiated (constructor is called). When the object falls out of scope (destructor is called) the timer returns the time elapsed since.
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
        cout << label << " -> " << duration.count() << " ms" << '\n';
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
    Timer timer("Outside");
    func();
    this_thread::sleep_for(chrono::milliseconds(230));
    return 0;
}
```

**Output**
```
Inside -> 109.2 ms
Outide -> 343.201 ms
```
