# Complexity and Big-O Notation
<img align="right" src="https://user-images.githubusercontent.com/55075129/126883333-3e22bcd2-522b-4f97-b457-1aae0304c565.png"/>

Time and space complexity analysis is an important part of problem solving. All competitive programming problems have a time limit and a memory limit. Even if your solution is logically 'correct', it may not meet these requirements. Thus, it is important to be able to estimate the runtime and memory usage of your algorithm to come up with solutions that pass.

The Big-O notation is used to describe how an algorithm scales with the size of the input. The following are some nice beginner articles on the same:
* [Learning & Understanding Big-O Notation](https://www.topcoder.com/blog/learning-understanding-big-o-notation/)
* [Time and space complexity](https://www.hackerearth.com/practice/basic-programming/complexity-analysis/time-and-space-complexity/tutorial/)
* [Codechef practice problems](https://discuss.codechef.com/t/multiple-choice-questions-related-to-testing-knowledge-about-time-and-space-complexity-of-a-program/17976)

#### Some things to try/note/remember (some might start to make sense at a later point)
* Try to find the time complexity and space complexity as you write code. With practice you will get better at it.
* Constraints can sometimes give away the expected time complexity of the solution.
    * You can assume approximately **10<sup>8</sup>** operations per second to run in time. 
    * You can use approximately **5 * 10<sup>7</sup>** `int`s worth of memory, be it through a single array of that size (say `arr[10000000]`), or multidimensional arrays (say `arr[10000][1000]`). Be wary that `long long` takes more space than `int`.
* STL/inbuilt functions have their [own time complexity](https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-summary.html) which you will need to factor in while finding complexity. Also, some STL containers require [more memory](https://pasteboard.co/J6ODpDi.jpg), which may lead to an MLE if you're not careful.