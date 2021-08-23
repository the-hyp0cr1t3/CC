# Binary Search
Binary search is an even more op technique that has the power to reduce an $\mathcal{O}(n)$ algorithm to an $\mathcal{O}(logn)$ one. The catch is that this can only be used when the data is **sorted** by some property.

The most trivial use of binary search is to locate an element in a sorted array or report that it does not exist, in $\mathcal{O}(logn)$ where $n$ denotes the size of the array. See [binary search for dummies](https://medium.com/karuna-sehgal/a-simplified-interpretation-of-binary-search-246433693e0b) if you are not familiar with the basic algorithm.

Binary search however, is much, much, more than that. When you find yourself in a tough spot with no way out, no light at the end of the tunnel and in complete darkness, ask yourself this
> Can I binary search the answer?

More often than not, the answer will be yes. A glimmer of hope, a shimmering light that marks the end of the tunnel. You start to slowly piece together the solution bit by bit, as you near the exit step by step. You've reached the end, the brightness now overwhelming, salvation at last. Mankind has never received a greater gift than binary search. Binary search is the way. Binary search is always the answer. Binary search is in itself, a religion. Join the cult, you won't regret it. Here are some inspiring quotes from our famous leaders

> No more hunger, no more poverty. It's all thanks to binary search.
>
> -- <cite>Mahatma Gandhi</cite>

> It's genius. I wish I just did a binary search from the start. Damn!
>
> -- <cite>Albert Einstein</cite>

> Just binary search bro.
> 
> -- <cite>Julius Caesar</cite>

What are you waiting for? Join the cult NOW! JK.

---

Binary search is not limited to just searching for an element. You can even binary search the optimal answer to a problem.

Consider [this](https://codeforces.com/contest/1201/problem/C) problem.
Lets define a function $\mathrm{check}(x)$ that returns `true` if it is possible to make the answer at least $x$ in at most $k$ operations, otherwise `false`.

| $x$ | $1$ | $2$ | $\ldots$ | $i$ | $i+1$ | $\ldots$ | $n-1$ | $n$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| $\mathrm{check}(x)$ | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :x: | :x: | :x: | :x: |

Observe that if $\mathrm{check}(x)$ is `true` then even $\mathrm{check}(x-1)$ must be `true`. Similarly, if $\mathrm{check}(x)$ is `false` then even $\mathrm{check}(x+1)$ must be `false`. This yields a property which appears to be sorted (first all trues, followed by all falses). What we are looking for is the largest value of $x$ for which $\mathrm{check}(x)$ returns `true`, which can be done with a simple binary search.

[Here](https://codeforces.com/contest/1201/submission/88821555) is my solution to the problem.

**Reading material:**
* The trivial algorithm - [Medium [B]](https://medium.com/karuna-sehgal/a-simplified-interpretation-of-binary-search-246433693e0b)
* Binary search over the answer - [Medium [B]](https://oldaddr.wordpress.com/2014/06/28/binary-search-the-answer/)
* A comprehensive tutorial
    * [Errichto [V]](https://www.youtube.com/watch?v=GU7DpgHINWQ)
    * [Topcoder [B]](https://www.topcoder.com/thrive/articles/Binary%20Search)
    * *CPH Ch 3,* pg [31](https://cses.fi/book/book.pdf#page=41) - [34](https://cses.fi/book/book.pdf#page=44)
* CF EDU on [Binary search](https://codeforces.com/edu/course/2/lesson/6)

<details>
<summary>Problems</summary>
<ul>
    <li><a href="https://codeforces.com/problemset/problem/706/B">CF 706 B</a></li>
    <li><a href="https://codeforces.com/problemset/problem/492/B">CF 492 B</a></li>
    <li><a href="https://codeforces.com/problemset/problem/1352/C">CF 1352 C</a></li>
    <li><a href="https://codeforces.com/contest/1187/problem/B">CF 1187 B</a></li>
    <li><a href="https://codeforces.com/contest/1201/problem/C">CF 1201 C</a></li>
    <li><a href="https://codeforces.com/contest/1208/problem/B">CF 1208 B</a></li>
    <li><a href="https://codeforces.com/contest/812/problem/C">CF 812 C</a></li>
    <li><a href="https://codeforces.com/contest/1118/problem/D2">CF 1118 D2</a></li>
</ul>
</details>
<br/>

*This page uses math latex formatting. Download the [extension](https://chrome.google.com/webstore/detail/github-math-display/cgolaobglebjonjiblcjagnpmdmlgmda) to render it.*