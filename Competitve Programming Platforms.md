# Competitive programming platforms

## Codeforces
While there are quite a few good sites for contests, I'd primarily recommend *[Codeforces](https://codeforces.com/)* for its active community, clean and minimalist UI and interesting problem statements.

### Problems
A [problem](https://codeforces.com/problemset/problem/4/A) typically consists of
* **Problem statement**, that details the task
* **Constraints** on the input (in simple terms, how big the input will be)
* **Input and Output** instructions (what to read, what to write)
* **Examples** to further explain the statement
* **Test cases** which your program will have to pass

You must submit a **solution** in a supported programming language of your choice that reads the input, applies some logic and prints the desired output within the mentioned time and memory limits. The solution should read from *STDIN* and print to *STDOUT* unless mentioned otherwise.

On submitting, it is run against a number of *test cases*. Each test case contains input in the stated format. Your solution must print the correct ouput for **every** test case for it to be accepted. It will receive a verdict based on its correctness, which will be one of the following
| Verdict | Description |
| :-----: | ----------- |
| ![Accepted](https://user-images.githubusercontent.com/55075129/126879602-fee79da3-cfc6-4c3d-9f85-d57ffa614f7d.png) | All test cases were passed and corresponding points are awarded. |
| ![WA](https://user-images.githubusercontent.com/55075129/126879515-6c366c46-6f93-4425-88ee-2ada0bdf01d7.png) | Your program output the wrong answer for a particular test case and was subsequently not run on the remaining test set. |
| ![Compilation error](https://user-images.githubusercontent.com/55075129/126879513-19aa11f7-79d8-4396-b07b-7228d438b7d4.png) | Your code could not be compiled, i.e, there is probably a syntactic error. Locally test it and fix the bug. Also ensure that you have selected the correct compiler when you submit. |
| ![Runtime error](https://user-images.githubusercontent.com/55075129/126879510-c67e3063-201b-45fe-b0de-74b229364ae7.png) | An error occurred during run time (see [here](https://stackoverflow.com/questions/19763756/what-is-a-runtime-error)). It is usually caused by accessing an array index that is out of bounds, division by **0** and so on. |
| ![TLE](https://user-images.githubusercontent.com/55075129/126879511-b057225a-84de-45a5-9f08-aa034a05741e.png) | Your program took too long, i.e. it could not run within the specified time limit under the given constraints. |
| ![MLE](https://user-images.githubusercontent.com/55075129/126879512-bca55dcb-7892-4f20-96fb-5fd11ed39320.png) | Similar to TLE, your program exceeded the memory limit. |

### Contests
There are **5-8 problems** in (mostly) **increasing order of difficulty**, which grant an increasing number of points. If you submit a solution which outputs the correct answer for **every** test case, you will be awarded (temporary*) points for it. Your rank after a contest is determined by the sum total of your points.

As time passes the total scorable points per problem decrease at a constant rate, something like:

| Time elapsed | Total scorable points |
| :---: | :---: |
| 0:00 | 500 |
| 0:01 | 498 |
| 0:02 | 496 |
| 0:03 | 490 |

Note that *there is a penalty for wrong submissions*. However, there is no penalty for a submission that fails the first test case.

Having everyone's code run on all 100+ tests during a contest would increase server load and result in long queue times. Thus, a system of pretests and main tests was introduced. Essentially, pretests are a small subset of the main tests, that are run against your code during the contest. You will see the verdict **Pretests passed** instead of **Accepted**.

| | |
| :---: | --- |
| ![pretests2](https://user-images.githubusercontent.com/55075129/126881634-2dba8b79-b3d9-4db8-b49b-aab1f12add51.png) | Your submission passed all pretests and corresponding points have been awarded (temporarily). |

After the contest has ended, every submission is run against the main (system) tests. It is possible that your solution passes the pretests but fails on some system test (**FST**). In that case, you lose the points that you had initially gotten for the problem and there is nothing you can do about it.

Another way to lose points is to get hacked. If you're unlucky enough, you may see the following verdict

| | |
| :---: | :--- |
| ![hacked](https://user-images.githubusercontent.com/55075129/126881518-c45698eb-58f3-4944-b79c-200ceb5a0f93.png) | This means that someone was able to generate a test case where your code gives one of the aforementioned errors. |

This immediately invalidates your submission and rescinds the points that you were awarded for it. In addition, it may award the hacker some points for the successful hacking attempt. Likewise, an unsuccessful hacking attempt may come with a penalty of some points.

To be eligible to hack someone you must lock your solution, which is possible only after you have solved it yourself during the contest. Note that locking a problem means that you will not be able to resubmit another solution even if someone else hacks your solution. Once you lock your solution, you can see the solutions of others and attempt to hack them if you wish to do so. Read more about hacking [here](https://codeforces.com/blog/entry/107753).

To learn more, see [link](https://codeforces.com/blog/entry/456) and [link](https://codeforces.com/blog/entry/4088).

### Rating System
Following every official contest are the rating changes. You gain or lose rating based on your rank and performance in the contest. Your rating is a number that goes up as you get better. Based on your rating, you fall under one of the 10 tiers listed on the right.

<img align="right" src="https://user-images.githubusercontent.com/55075129/126892885-b464c9f1-8eeb-4ffa-b49e-fa6f2e68384f.png"/>
<br/>

There are broadly two divisions, namely **Div. 1** (*2100 rating and above*) and **Div. 2** (*below 2100 rating*). Contests are usually rated for one of the divisions. For example, `Codeforces Round #735 (Div. 2)` was rated for all Div. 2 participants (with rating below 2100) only, while `Codeforces Round #732 (Div. 1)` was rated for Div. 1. Some contests such as `Codeforces Round #718 (Div. 1 + Div. 2)`, can be rated for both divisions. Additionally, there are contests rated for **Div. 3** (*below 1600 rating*) only, such as `Codeforces Round #710 (Div. 3)` and also those rated for **Div. 4** (*below 1400 rating*) only, such as `Codeforces Round #640 (Div. 4)`. As the rating caps suggest, Div. 1 contests are the hardest.

<br/>

 If you are interested, here's a very cool blog that covers a lot more aspects of the website: [How to use Codeforces [GUIDE]](https://codeforces.com/blog/entry/99660).
 
---

## AtCoder
Similar to *Codeforces*, *[AtCoder](https://atcoder.jp/)* is another programming contest website, based in Japan. There are two main types of official contests on AtCoder:
* **AtCoder Beginner Contest (ABC)**: This is mainly targeted at those who are new to competitive programming. The problems are usually easy and educational, great for beginners.
* **AtCoder Regular Contest (ARC):** Comparable to a Codeforces Div. 2 Round, slighlty on the harder side.
* **AtCoder Grand Contest (AGC)**: Arguably harder than Codeforces Div. 1 Rounds. Problems usually have high originality and require interesting observations.

ABCs are usually held every weekend and they consist of 6 problems which are to be solved in a time limit of 100 minutes. It is rated for participants in the range 0 – 1999.The problems are generally arranged in an increasing order of difficulty and hence grant an increasing number of points (100 for Task A, 200 for Task B and so on).When you solve a problem, you get the score assigned to it. However, you would incur a penalty for every incorrect submission (no deduction from score). The penalties are computed as (the time you spend to get your current score) + (5 minutes) * (the number of incorrect attempts).  Competitors are ranked first by total scores, then by penalties. The verdicts a submission may get are quite similar to the ones on Codeforces.

For more info, see [Getting started with AtCoder](https://atcoder.jp/posts/2).

### Rating system
In each contest, you get performance. This value represents how well you've performed in a contest. Your rating is computed as the weighted average (recent contests have more weights) of performances. After 10 rated contests, you can assume that your rating is close to your real strength.
