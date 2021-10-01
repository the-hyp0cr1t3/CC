# Getting into Competitive Coding

Programming is all about writing code to solve problems or tasks. Competitive programming makes a sport out of this, where contestants compete (usually online) to solve a bunch of such problems in a limited amount of time.

## What's in a problem?
Problems are primarily math, logic and/or algorithm based and typically look something like [this](https://codeforces.com/problemset/problem/4/A). Such problems usually consist of a statement (that details the task), the input and output format, constraints on the input and some examples (will be further explained later on).

Try [this](https://codeforces.com/problemset/problem/71/A) problem. Read the statement carefully and try to understand what it is asking. Once you figure it out, all that's left is to code it.

Here's what one of the many possible solutions looks like.
<details>
    <summary>C++ code</summary>

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s.length() <= 10)
            cout << s << endl;
        else
            cout << s.front() << s.length()-2 << s.back() << endl; 
    }
    return 0;
}
```
</details>

## Choosing a language
Most competitive programmers prefer C++, and for [good reason](https://www.codingninjas.com/blog/2018/04/11/the-best-languages-for-competitive-programming/). However, Java and Python are also fairly popular. Knowing a programming language is the only pre-requisite. While I do say that, you are by no means expected to be an expert. If you can manage a basic hello world and can work with loops and conditionals, you are good to go.

**Note**: The code snippets in this guide will be in C++ since it is arguably the best language for competitive programming ~~and not because I do not know any other languages :/ UPD: I learnt a little bit of Java and Pythom :)~~

## Setting up an IDE
If you haven't already set up an IDE, you may find use for one of the following links. I personally use Sublime Text, with VS code being my second choice, but it is a matter of personal preference.
* [Sublime Text](./Sublime%20Text%20Setup.md)
* [VS code](https://medium.com/@chinmaykulkarni8/how-to-setup-visual-studio-code-for-c-c-java-python-competitive-programming-angular-22fdc9b1f4c6) and a [cool extension](https://github.com/agrawal-d/competitive-programming-helper/)

## Competitive coding platforms
There are many platforms that host programming contests and allow you to practice solving problems, among other things. One such platform is [Codeforces](https://codeforces.com/), which I primarily use and recommend.

[Here](./Competitve%20Programming%20Platforms.md) is a detailed guide I've written about problem statements, how contests work and the rating system on Codeforces (and a few other platforms).

## Get started
Here are a few problems for you to get started with. They're really simple and should help you understand how to submit code on online platforms.

<details>
    <summary> Click </summary>
    <ul>
        <li><a href="https://atcoder.jp/contests/abc127/tasks/abc127_a">AtCoder ABC127A</a></li>
        <li><a href="https://codeforces.com/problemset/problem/4/A">Codeforces 4A</a></li>
        <li><a href="https://atcoder.jp/contests/abc126/tasks/abc126_a">AtCoder ABC126A</a></li>
        <li><a href="https://www.codechef.com/problems/HS08TEST">Codechef HS08TEST</a></li>
        <li><a href="https://atcoder.jp/contests/abc125/tasks/abc125_a">AtCoder ABC125A</a></li>
        <li><a href="https://www.codechef.com/problems/FLOW006">Codechef FLOW006</a></li>
        <li><a href="https://codeforces.com/problemset/problem/158/A">Codeforces 158A</a></li>
        <li><a href="https://atcoder.jp/contests/abc124/tasks/abc124_a">AtCoder ABC124A</a></li>
        <li><a href="https://www.codechef.com/problems/FLOW001">Codechef FLOW001</a></li>
        <li><a href="https://www.codechef.com/problems/START01">Codechef START01</a></li>
        <li><a href="https://codeforces.com/problemset/problem/231/A">Codeforces 231A</a></li>
        <li><a href="https://codeforces.com/problemset/problem/71/A">Codeforces 71A</a></li>
        <li><a href="https://www.codechef.com/problems/INTEST">Codechef INTEST</a></li>
    </ul>
</details>

Once you're done with these, head on over to the [problemset](https://codeforces.com/problemset?order=BY_RATING_ASC) ~~I liked bugabooset better~~ on Codeforces and sort problems by rating. Solve some easy problems till you get a feel for it.

## What's next?
Once you familiarize yourself with these things, here are some things you could consider doing next:

* **Time complexity:** Take a look at [time and space complexity](./Complexity%20and%20Big-O%20Notation.md), as you will soon realise that not all logically 'correct' solutions pass the given constraints.

* **Learn new concepts/topics:** Develop your problem solving skills by learning new topics, one at a time. [Here's](./Beginner%20Topics) a collection of some common beginner topics and problems on the same. The [cses problemset](https://cses.fi/problemset/list/) is another great place to practice standard problems from various topics.

* **Practice:** Turn to the codeforces [problemset](https://codeforces.com/problemset), and sort by difficulty and tags. Grind problems because there's nothing like **practice, practice, practice**.

* **Contests:** Participate in live [contests](https://codeforces.com/contests) or take [virtual](https://codeforces.com/blog/entry/70036) ones. Virtual contests are a way to participate in or experience old contests that have already happened in the past.

<details>
    <summary>The secret formula</summary>
    <img src="https://user-images.githubusercontent.com/55075129/88116572-75eb0d80-cbd6-11ea-968a-5807066aeabb.jpg" alt="Practice">

    In all seriousness though
    Learn new topic > Practice problems > Improve speed > Learn new topic > Practice ... Rinse and repeat.
</details>

## Extras
* **Cool repos:** [YouKn0wWho](https://github.com/ShahjalalShohag/code-library), [smax](https://github.com/mzhang2021/cp-library), [Ashishgup](https://github.com/Ashishgup1/Competitive-Coding)
* **Rating predictor:** [CF Predictor](https://cf-predictor-frontend.herokuapp.com/) or [Carrot](https://github.com/meooow25/carrot/)
* **Problem/Contest parser:** [Competitve Companion](https://github.com/jmerle/competitive-companion) coupled with
    * [Competitve Programming Helper](https://github.com/agrawal-d/competitive-programming-helper/) (for VS code)
    * [FastOlympicCodingHook](https://codeforces.com/blog/entry/60627?#comment-593580) \[[alt](https://codeforces.com/blog/entry/85342)\] (for Sublime Text)
* **Stats:** [Codeforces Visualizer](https://cfviz.netlify.com/), [Codeforces Practice Tracker](https://codeforces.com/blog/entry/78203), [CF Analytics](https://codeforces.com/blog/entry/93417)
* **Misc:** [Codeforces Live Telegram Bot](https://codeforces.com/blog/entry/82669), [Codeforces Enhancer](https://codeforces.com/blog/entry/74062), [Codeforces Customizer](https://codeforces.com/blog/entry/93536), [Dark mode](https://codeforces.com/blog/entry/93606)
