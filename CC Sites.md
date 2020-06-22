# Competitive coding sites

## Codeforces

While there are quite a few good sites for contests, I'd primarily recommend *[Codeforces](https://codeforces.com/)* for its amazing community, interface and problem statements.

### Problems
A problem typically consists of a problem statement (that details the task), constraints on the input (in simple terms, how big the input will be), input and output instructions (what to read, what to write), and finally a sample test case.

[Here](https://codeforces.com/problemset/problem/4/A) is an example.

### Contests and how they work

There are **5-8 problems** in (mostly) **increasing order of difficulty**, which grant an increasing number of points (say 250 for problem A, 500 for B, 750/1000 for C, etc). Your rank after a contest is determined by the sum total of your points. 
As time passes, the scores for each problem reduce at a rate of n/250 points per minute, where n is the initial number of points awarded by the problem, and stops reducing after a certain point. Given below is an example of the relation between submitting problem A after x minutes vs the y points that are awarded for it.

1 min - 498 points\
2 mins - 496 points\
5 mins - 490 points

On submitting your code, it is run against a number of *test cases*. If it outputs the correct answer for *every* test case, you will be awarded (temporary*) points for it. There is a penalty for wrong submissions, usually worth -50 points (each time) that remove from the remaining points you can get from the question. There is no penalty for a wrong submission that fails the first test case. Following are the most common verdicts a submission may get after being judged.

#### Accepted (AC)
All test cases passed and corresponding points are awarded.

#### Wrong Answer (WA)
Your program output the wrong answer for a particular test case and was subsequently not run on the remaining test set. Usually, there is no partial marking for contests on Codeforces, so you have to pass all tests.

#### Runtime Error (RTE)
An error occurred during run time; Division by 0, accessing an array index that is out of bounds, etc.

#### Time Limit Exceeded (TLE)
Took too long. Your program is not able to run within the specified time limit with the given constraints on input. It thus becomes important to be able to judge the **time complexity** of your algorithm and ensure it satisfies the time limit, given the constraints, as discussed later.

#### Memory Limit Exceeded (MLE)
Similar to TLE, your program exceeded the memory limit mentioned.

#### Compilation Error
Your code could not be compiled, i.e, there is probably a syntactic error. Locally test it and fix the bug. Also ensure that you have selected the correct compiler when you submit.

Having everyone's code run on all 100+ tests during a contest would result in heavy server load and long queue time to get a verdict. Thus, a system of pretests and main tests was introduced. Essentially, pretests are a small subset of the main tests, that are run against your code during the competition. You may see the verdict -

#### Pretests Passed
This means that your submission successfully passed all pretests and corresponding points have been awarded (temporarily).

After the contest has ended, every submission is then run against the main tests. It is possible that you pass pretests but fail system tests, or main tests. In that case, you lose the points that you initially got for the problem and there is nothing you can do about it. Git good. Another way you can lose points (yay) is if you get hacked. Of all verdicts, this one is the most dreaded, and for good reason.

#### Hacked
This means that someone was able to supply a test case where your code gives one of the aforementioned errors. This immediately invalidates your submission and rescinds the points that you were awarded for it. In addition, it awards the hacker 100 points for the successful hacking attempt. An unsuccessful hacking attempt comes with a penalty of 50 points. There are hacks that can be made during a contest and those that can be made after, in what's called the 12 hour hacking phase. To be able to hack other people's solutions during a contest, you must have solved the problem yourself and *locked* it. In case you do, you will not be able to resubmit if it gets hacked by someone else or you identify any flaws in it. However, now you can see other people's submissions and can (try to) come up with test cases to fail their code.

For more info on the rules, visit [link](https://codeforces.com/blog/entry/456) and [link](https://codeforces.com/blog/entry/4088)

### Rating System
Following every official contest, are the rating changes. You gain or lose rating based on your rank and performance. Your rating is a number that goes up as you get better.

There are 3 broad divisions, namely
* Div. 1
* Div. 2
* Div. 3

Original, I know. Participants in a Div. 3 contest rated *1600 and below* **only** are given rating changes for the contest. In other words, the contest remains unrated for those above R1600. Similarly, in a Div. 2 contest, those rated either *1900* or *2100 and below* (depends on the contest) **only** are affected by rating changes. Div. 1 contests are the hardest and are rated for all. Subsequently in terms of difficulty, **Div. 3 < Div. 2 < Div. 1**.
Some common types of division-wise contests held are
* Div. 2 only
* Div. 3 only
* Div. 1 and Div. 2 (in parallel)
* Div. 1 + Div. 2 (Mix of both, rated for all)

Lastly, there are currently 10 different tiers on codeforces. Each tier is specified by a rating range, **Newbie** (Gray) being the lowest, and **Tourist** (Legendary Grandmaster) being the highest.

## AtCoder
Similar to Codeforces, [AtCoder](https://atcoder.jp/) is another programming contest website, based in Japan. **AtCoder Beginner Contests** are a great way to improve your basic implementation skills.

[Getting started with AtCoder](https://atcoder.jp/posts/2)

## CodeChef
[CodeChef](https://www.codechef.com/)

## HackerEarth
[HackerEarth](https://www.hackerearth.com/challenges/)

## FoolsHaven
[FoolsHaven](https://www.youtube.com/watch?v=dQw4w9WgXcQ)
