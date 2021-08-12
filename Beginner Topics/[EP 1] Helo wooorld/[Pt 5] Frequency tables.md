# Frequency tables
Consider an array of elements. The frequency of a particular element is the number of times it occurs in the array. Calculating the frequencies of each element can be very useful to solve certain kinds of problems.

Frequency tables are usually built on arrays  or vectors, but can also be built on maps (or hash maps) when the range of values is too large to fit in memory.
The tradeoff is that maps have $\mathcal{O}(log n)$ lookup time, unlike arrays and vectors which have $\mathcal{O}(1)$ lookup time (Hash maps have $\mathcal{O}(1)$ lookup time *on average*, not in the worst case).

**Reading material:**
* [GFG [B]](https://www.geeksforgeeks.org/counting-frequencies-of-array-elements/)

<details>
<summary>Problems</summary>
<ul>
    <li><a href="https://codeforces.com/problemset/problem/1121/A">CF 1121 A</a></li>
    <li><a href="https://codeforces.com/problemset/problem/1189/B">CF 1189 B</a></li>
    <li><a href="https://codeforces.com/problemset/problem/1144/C">CF 1144 C</a></li>
    <li><a href="https://codeforces.com/problemset/problem/1183/D">CF 1183 D</a></li>
</ul>
</details>
<br/>

<details>
<summary>Challenging problems</summary>
<ul>
    <li><a href="https://codeforces.com/problemset/problem/1213/D2">CF 1213 D2</a></li>
    <li><a href="https://codeforces.com/problemset/problem/1269/B">CF 1269 B</a></li>
</ul>
</details>