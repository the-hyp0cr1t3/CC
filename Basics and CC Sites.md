# Competitive coding sites

## Codeforces

While there are quite a few good sites for contests, I'd primarily recommend *CodeForces* for it's amazing community, interface and problem statements.

### Problems
Each problem typically consists of a problem statement (that details the task), constraints on the input (in simple terms, how big the input will be), input and output instructions (what to read, what to write), and finally a sample test case.

[Here](https://codeforces.com/problemset/problem/4/A) is an example.

### Contests and how they work

There are **5-8 problems** in (mostly) **increasing order of difficulty**, which grant an increasing number of points (say 250 for problem A, 500 for B, 750/1000 for C, etc).
As time passes, the scores for each problem reduce at a rate of n/250 points per minute, where n is the initial number of points awarded by the problem, and stops reducing after a certain point. Given below is an example of the relation between submitting problem A after x minutes vs the y points that are awarded for it.

1 min - 498 points
2 mins - 496 points
5 mins - 490 points

On submitting your code, it is run against a number of ***test cases***. If it outputs the correct answer for *every* test case, you will be awarded (temporary*) points for it. Your rank is determined by the sum total of your points. Following are the most common verdicts a submission may get after being judged.

#### Wrong Answer (WA)
Your program output the wrong answer for a particular test case and was subsequently not run on the remaining test set. Usually, there is no partial marking for contests on Codeforces, so you have to pass all tests.

#### Runtime Error (RTE)
An error occured during run time; Division by 0, accessing an array index that is out of bounds, etc.

#### Time Limit Exceeded (TLE)
Took too long. Your program is not able to run within the specified time limit with the given constraints on input. It thus becomes important to be able to judge the **time complexity** of your algorithm and ensure it satifies the time limit, given the constraints, as discussed later.

#### Memry Limit Exceeded (MLE)
Similar to TLE, your program exceeded the memory limit mentioned.

#### Compilation Error
Your code could not be compiled, i.e, there is probably a syntactic error. Locally test it and fix the bug. Also ensure that you have selected the correct compiler when you submit.

#### Accepted (AC)
Yay, it passed all the tests.

As mentioned above, there is a penalty for wrong submissions (anything but AC), usually worth -50 points (each time) to the remaining points that the question will award if you get an AC afterwards. There is no penalty for a wrong submission of any kind that fails the first test case.

Now these points given to you are only representative of how you are doing at that point and are NOT FINAL, there are ways you can still lose points for these questions. Now the essence of the problem is that pretests must be fast and therefore aren't perfect which leads to 2 possibilities :

1.) Getting 'hacked' - basically people who are confident in their solution can 'lock' their problems (they won't be able to edit it any more) after which they can see other people's accepted code for that problem and if finding any problems with it suggest an input (in the question's given syntax) that makes a problem give a different answer from the proper code (written by the problem setters). If it does the hacker gets 100 points and the incorrect solution will be considered 'hacked'. For the hacked person’s new solution to pass pretests they'll have to pass both the pretests AND the 'hack' test which made their code fail.

2.) The second is the system tests - a more comprehensive set of 50-100 tests at the end of the contest which test many 'edge cases' (special/difficult inputs which a program might have missed), additionally added are ANY hacks which worked on ANYONE during the contest.

Basically if you fail to fix your code after getting hacked or fail system tests you will get ZERO points for that problem.

After the contest once system testing has finished, your final ranks will be shown and your rating will be changed.

(NOTE: Educational rounds and a few other contests instead operate under ICPC / extended ICPC rules. However the rules are mostly the same and the differences are small enough not to cause problems.)

For those who want to read the official CodeForces blogs on the same :

Basic rules : https://codeforces.com/blog/entry/456
Advanced rules : https://codeforces.com/blog/entry/4088

𝐀𝐭𝐂𝐨𝐝𝐞𝐫

I would also highly suggest that those of you who are new to competitive coding also try the AtCoder Beginner Contests to improve your basic implementation skills.
All of the recent AtCoder Beginner Contest rounds (Round 43 onward) have English problem statements.

AtCoder Main Site : https://atcoder.jp/
Getting started with AtCoder : https://atcoder.jp/posts/2

𝗣𝗮𝗿𝘁 𝟮 : 𝗖𝗼𝗺𝗽𝗹𝗲𝘅𝗶𝘁𝘆 𝗔𝗻𝗮𝗹𝘆𝘀𝗶𝘀

I would recommend watching the following videos to gain a basic understanding of complexity analysis.

General time complexity : https://www.youtube.com/watch…
Recursive time complexity : https://www.youtube.com/watch?v=ncpTxqK35PI

Once you have watched the above videos I would suggest trying these questions to ensure you have understood the concept :

https://www.geeksforgeeks.org/practice-questions-time-comp…/

Now in general the number of operations that can be executed on the CodeForces platform in 1 second using C/C++/Java is ~10^8.

However you have to remember that we neglect the constant when calculating complexity.
For example say we have an algorithm that contains a for loop that has a large number of calculations (say 20-30) per iteration.
Now if you were to run the loop 10^8 times (n=10^8) , the number of operations would actually be in the range of ~10^9 and would take more than a second.
As such it is a good idea to try to keep the number of operations per second calculated using time complexity a bit below the maximum possible.

Ideal/Maximum operations per second for various complexities

Time complexity [ideal , maximum]

O(n) [ 10^6 , 10^8]
O(n^2) [ 10^3 , 10^4 ]
O(n^3) [ 100 , 500 ]
O(n^4) [ 50 , 100 ]
O(n logn) [ 10^5 , 5*(10^6) ]
O(log n) [ 10^100 , 2^(10^7) ]
O(2^n) [ 20 , 26 ]

Ideal numbers should generally work on nearly all platforms , the maximum numbers are written with respect to CodeForces.

One more thing to note is that 'logn' here represents log2(n) NOT log10(n) , equivalent to a multiplicative factor of log2(10) [approx. 3.33] to the answer of log10(n).
