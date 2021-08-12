# Prefix sums
Given an array $a$ of $n$ elements, prefix sums allow you to calculate the sum of any range of elements $[l, r]$ $1 \leq l \leq r \leq n$ in $\mathcal{O}(1)$ constant time (with $\mathcal{O}(n)$ pre-processing).

The trick is to pre-calculate (to calculate once beforehand for multiple usages later) an array $prefix$, of cumulative sums. For each $i$ from $1$ to $n$, $prefix_i$ stores the sum $a_1 + a_2 + \ldots + a_i$. Then, the sum of elements in the range $[l, r]$ can be easily found out as $prefix_r - prefix_{l-1}$.

**Reading material:**
* [Peltorator [V]](https://codeforces.com/blog/entry/88474) (Use english subtitles)
* [USACO [B]](https://usaco.guide/silver/prefix-sums?lang=cpp)
* 2D prefix sums - [USACO [B]](https://usaco.guide/silver/more-prefix-sums?lang=cpp)
* Range updates using prefix sums - [Codeforces [B]](https://codeforces.com/blog/entry/86420)

<details>
<summary>Problems</summary>
<ul>
    <li><a href="https://www.spoj.com/problems/CSUMQ/">Spoj CSUMQ</a></li>
    <li><a href="https://www.codechef.com/problems/SHIVIGOD">Codechef SHIVIGOD</a></li>
    <li><a href="https://codeforces.com/contest/433/problem/B">CF 433 B</a></li>
    <li><a href="https://codeforces.com/contest/276/problem/C">CF 276 C</a></li>
    <li><a href="https://codeforces.com/contest/1363/problem/B">CF 1363 B</a></li>
    <li><a href="https://codeforces.com/problemset/problem/1253/C">CF 1253 C</a></li>
    <li><a href="https://codeforces.com/problemset/problem/1265/C">CF 1265 C</a></li>
    <li><a href="https://codeforces.com/problemset/problem/1118/B">CF 1118 B</a></li>
    <li><a href="https://codeforces.com/contest/1200/problem/D">CF 1200 D</a></li>
</ul>
</details>
<br/>

*This page uses math latex formatting. Download the [extension](https://chrome.google.com/webstore/detail/github-math-display/cgolaobglebjonjiblcjagnpmdmlgmda) to render it.*