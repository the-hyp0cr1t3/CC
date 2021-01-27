# Complexity and Big-O Notation
All competitive programming problems have a time limit and a memory limit. Even if your solution is logically 'correct', it may not meet these requirements. Thus, it is important to be able to estimate the runtime and memory usage of your algorithm.
## Time Complexity
The time complexity of an algorithm gives an estimate of runtime. It is denoted by **O(f(N))** where **f(N)** is a function of input size N. As input size increases, constant coefficients and lower order terms start to matter less. This is why they are not mentioned in the Big-O notation. For example, if f(N) = 3(N<sup>2</sup>) + 2N + 1, complexity is simply **O(N<sup>2</sup>)**.

#### Constant time - O(1)
If your algorithm does not depend on the size of your input, it will perform in constant time. Mathematical expressions are common examples.\
**Safe zone**: any value of N

#### Linear time - O(N)
This means that as the size of your input increases, the runtime of your algorithm also increases at the same rate, i.e, linearly. If your input is an array, then there is a constant number of operations performed on each of its N elements.\
**Safe zone**: N <= 1e6 or 1e7 (10<sup>6</sup> or 10<sup>7</sup>) will run in 1 second.

#### Quadratic time - O(N<sup>2</sup>)
Quadratic Time Complexity represents an algorithm whose performance is directly proportional to the squared size of the input data set. Within our programs, this time complexity will occur whenever we nest over multiple iterations within the data sets.\
**Safe zone**: N <= 5000

#### Cubic time - O(N<sup>3</sup>)
Similar to quadratic, it is another polynomial time complexity (thing?).\
**Safe zone**: N <= 500

#### Logarithmic time - O(log N)
You definitely would have heard of Binary search, the most common example of logarithmic time. At each step, the problem is halved. If x operations are performed on input of size N, (2<sup>x</sup> = N) => (x = log<sub>2</sub>N).\
**Safe zone**: N <= 1e18 (Input usually wont exceed 1e18 anyway as anything larger may overflow conventional data types)

#### Log-linear time - O(N.log N)
Efficient sorting algorithms run in log-linear time. Read up on Merge Sort if you're curious.\
**Safe zone**: N <= 1e6

#### Exponential time - O(2<sup>N</sup>)
The runtime of your algorithm increases at an exponential rate. The (most) naive method of finding fibonacci numbers is exponential in time. \
**Safe zone**: N <= 20

[Table of common complexities](https://pasteboard.co/J6OCrxR.jpg) and their corresponding input sizes. \
Time complexities of various [STL containers](https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-summary.html) (useful later).

## Space Complexity
Space Complexity of an algorithm is an estimate of the memory usage of an algorithm as a function of its input size. Similar to time complexity, space complexity also uses the Big-O notation.\
Memory limit on Codeforces is usually 256 MB. This is just sufficient to store 1D arrays or vectors of size 1e6. For 2D arrays it is 1e3 (1e3*1e3 = 1e6) and so on.\
Note that some STL containers require more memory, which may lead to an MLE if you're not careful.

Space occupied by different STL containers: [Link](https://pasteboard.co/J6ODpDi.jpg)
