# Getting into Competitive Coding

Programming is all about writing code to solve problems or tasks. Competitive programming makes a sport out of this, where contestants compete (usually online) to solve a bunch of such problems in a limited amount of time.

Problems are primarily math, logic and/or algorithm based and typically look something like [this](https://codeforces.com/problemset/problem/71/A). Such problems usually consist of a statement (that details the task), the input and output format, constraints on the input and some examples.

## What's in a problem?
Let's jump right in. Take a look at this [problem](https://codeforces.com/problemset/problem/71/A). Read the statement carefully and try to understand what it is asking. Once you figure this out, all that's left is to code it.

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
Most competitive programmers prefer C++, and for [good reason](https://www.codingninjas.com/blog/2018/04/11/the-best-languages-for-competitive-programming/). However, Java and Python are also fairly popular. Knowing a programming language is the only pre-requisite.

**Note**: The code snippets in this guide will be in C++ since it is arguably the best language for competitive programming ~~and not because I do not know any other languages :/~~

## Setting up an IDE
If you haven't already set up an IDE, you may find use for one of the following links.\
[Link](Setting%20up%20Sublime.md) to setting up Sublime\
[Link](https://github.com/agrawal-d/competitive-programming-helper/) to VS extension (cph)

## Competitive coding platforms
There are many platforms that host programming contests and allow you to practice solving problems, among other things. One such platform is [Codeforces](https://codeforces.com/), which I primarily recommend and use.
[Here](CC%20Sites.md) is a detailed guide I've written about it (and a few other platforms).

## Get started
Head on over to [problemset](https://codeforces.com/problemset?order=BY_RATING_ASC) on Codeforces and sort by rating. Solve some easy problems till you get a feel for it.

## What's next?
Once you are familiarize yourself with these things, here are some things you could consider doing next:

* Take a look at [time (and space) complexity](https://github.com/the-hyp0cr1t3/CC/blob/master/Complexity%20and%20Big-O%20Notation.md), as will you soon realise that not all logically 'correct' solutions pass the given constraints.

* Learn C++ STL. STL, or Standard Template Library, is a huge library of useful functions. If you're not already familiar with it, [this](https://www.hackerearth.com/practice/notes/standard-template-library/) is a good place to start. Try out a few problems [here](https://hackerrank.com/domains/cpp/stl).

* Develop your problem solving approach by tackling topics one at a time. Here's a collection of some common beginner [topics](https://github.com/the-hyp0cr1t3/CC/tree/master/Topics) and problems on the same.

* Turn to the Codeforces [problemset](https://codeforces.com/problemset), and sort by difficulty and tags. Grind problems because there's nothing like **practice, practice, practice**.

* Participate in live [contests](https://codeforces.com/contests) or take [virtual](https://codeforces.com/blog/entry/70036) ones. Virtual contests are a way to participate in or experience old contests that have happened already.

<details>
    <summary>The secret formula</summary>
    <img src="https://user-images.githubusercontent.com/55075129/88116572-75eb0d80-cbd6-11ea-968a-5807066aeabb.jpg" alt="Practice" style="width:20px;height:20px;">

    In all seriousness though
    Learn new topic > Practice problems > Improve speed > Learn new topic > Practice ... Rinse and repeat.
</details>

## Extras
[Track your progress](https://cfviz.netlify.com/)\
[Rating Predictor](https://cf-predictor-frontend.herokuapp.com/) (Download the extension)
