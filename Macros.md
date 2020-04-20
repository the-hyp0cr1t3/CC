# Macros
Anything that starts with a **'#'** is a *preprocessor directive*. A macro is a preprocessor directive which behaves like a find and replace tool. You may read more about it from [here](http://www.cplusplus.com/doc/tutorial/preprocessor/). 

When it comes to cp, macros can prove to be quite useful. Here are a few common macros (with a few other useful things here and there).

```c++
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
