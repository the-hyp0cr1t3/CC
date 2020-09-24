# Macros
Anything that starts with a **'#'** is a *preprocessor directive*. A macro is a preprocessor directive which in essence performs a find and replace on code before it is actually compiled. You may read more about it from [here](http://www.cplusplus.com/doc/tutorial/preprocessor/). 

When it comes to cp, macros are quite useful. Here are a few common ones (along with some other useful things).

```c++
#define FastIO cin.tie(nullptr)->sync_with_stdio(false);
#define endl '\n'
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define sz(x) (int)x.size()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define trace(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef vector<int> vi; 
typedef pair<int, int> pii;

const int MOD = 1000000007;  //1e9 + 7
const int INF = 2000000000;  //2e9
const ll LLINF = 1000000000000000000;  //1e18

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

const int MxN = 2e5 + 5;
```

## A few notes
### FastIO
```c++
cin.tie(nullptr)->sync_with_stdio(false);
```
The ```std::cin``` and ```std::cout``` streams may sometimes be too slow. Thus when there is large input, it is common practice to disable synchronization with stdio and flushing before every ```cin```. You may refer to [this](https://www.geeksforgeeks.org/fast-io-for-competitive-programming/) for a better understanding on what it does, and how it works.

### endl vs '\n'
Using ```'\n'``` is better (faster) than using ```std::endl``` (in the context of cp) and [here's](https://www.educative.io/edpresso/what-is-the-difference-between-endl-and-n-in-cpp) why. 

I like typing one more than the other (hence the macro), but it's completely fine to type ```'\n'``` as is.

However, remember to use ```std::endl``` in [interactive problems](https://codeforces.com/blog/entry/45307), not ```'\n'``` as it is required to flush the output.

### The size() method and where you can go wrong with it
The ```size()``` method, compatible with most STL containers, returns a value of type ```size_t```, which is an *unsigned int*. When comparisons are made between values of different data types, the compiler (implicitly) typecasts one of them to the other, and when a negative integer of type ```int``` is casted to an ```unsigned int```, the expression may evaluate to a different value altogether. 

```c++
vector<int> vect{1, 2, 3};
for(int i = 0; i < (int)vect.size(); i++)
  // do stuff
```
It is thus advisable to explicitly cast it to ```int``` every time, as shown above.

### Debugging using the power of macros
The *stringizing* operator (*#*) turns source code into text tokens, i.e, it can turn parameters into string literals.

Try this out.
```c++
#include <iostream>
using namespace std;
#define watch(x) cout << #x << " = " << x << endl
int main() {
    int a = 5;
    watch(a);
    return 0;
}
```
