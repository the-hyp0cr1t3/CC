# Sorting
Sorting is a very important technique that is used in a lot of problems. There are many standard sorting techniques that you should know, although you will almost never have to implement them yourself. You may refer to [this](https://www.programiz.com/dsa/sorting-algorithm).
<br/>
You may also read up on [bubble sort](https://www.programiz.com/dsa/bubble-sort), [selection sort](https://www.programiz.com/dsa/selection-sort), [insertion sort](https://www.programiz.com/dsa/insertion-sort), [merge sort](https://www.programiz.com/dsa/merge-sort), [quick sort](https://www.programiz.com/dsa/quick-sort), [counting sort](https://www.programiz.com/dsa/counting-sort) and [heap sort](https://www.programiz.com/dsa/heap-sort) work and their respective time complexities (both average and worst case if they differ). Here is an [optional read](https://theartofmachinery.com/2019/01/05/sorting_is_nlogn.html) on why the best asymptotic time complexity for comparison based sorting algorithms is $\mathcal{O}(nlogn)$.
<br/>
[Merge sort](https://medium.com/karuna-sehgal/a-simplified-explanation-of-merge-sort-77089fe03bb2) in particular is important to know since some problems can be solved using some variation of it.
<br/>
Another sorting algorithm worth mentioning is [counting sort](https://www.geeksforgeeks.org/counting-sort/), which works in $\mathcal{O}(n)$.

**Reading material:** [CPH Ch 3: Sorting](https://cses.fi/book/book.pdf#page=35)

<details>
<summary>Problems</summary>
<ul>
    <li><a href="https://codeforces.com/contest/1041/problem/A">CF 1041 A</a></li>
    <li><a href="https://codeforces.com/problemset/problem/456/A">CF 456 A</a></li>
    <li><a href="https://codeforces.com/problemset/problem/1399/A">CF 1399 A</a></li>
    <li><a href="https://codeforces.com/problemset/problem/1092/B">CF 1092 B</a></li>
    <li><a href="https://codeforces.com/problemset/problem/1189/B">CF 1189 B</a></li>
    <li><a href="https://codeforces.com/problemset/problem/984/A">CF 984 A</a></li>
    <li><a href="https://codeforces.com/problemset/problem/339/A">CF 339 A</a></li>
    <li><a href="https://codeforces.com/problemset/problem/977/C">CF 977 C</a></li>
    <li><a href="https://codeforces.com/problemset/problem/1174/B">CF 1174 B</a></li>
</ul>
</details>
<br/>

*It is recommended to use the built-in sorting methods because they are trusted implementations which are optimized for best performance. Further, you may save time not having to implement a sorting algorithm yourself.*

### C++ std::sort
In C++ the `<algorithm>` header file contains an implementation of a sorting algorithm (introsort) that can be called within your program as [std::sort](https://en.cppreference.com/w/cpp/algorithm/sort). The `std::sort` function works on arrays and vectors of all types. For an array $a$ of size $n$ it would be invoked as `sort(a, a + n)` whereas for a vector $v$ it would be invoked as `sort(v.begin(), v.end())` to sort it completely.
* [Sorting an array](https://www.geeksforgeeks.org/sort-c-stl/)
* [Sorting a vector](https://www.journaldev.com/37678/sorting-a-vector-in-c-plus-plus)

Further, you can sort any range $[l, r)$ $(0 \leq l \leq r \leq n)$ in a container. The syntax is `sort(a + l, a + r)` (for arrays), and `sort(v.begin() + l, v.begin() + r)` (for vectors).

**Note**: You can even use `std::sort` on strings. For a string $s$, `sort(s.begin(), s.end())` would sort the characters of the string.

See also [lambdas](../../Some%20Neat%20tricks.md#lambdas) for custom comparison sorting.

*This page uses math latex formatting. Download the [extension](https://chrome.google.com/webstore/detail/github-math-display/cgolaobglebjonjiblcjagnpmdmlgmda) to render it.*