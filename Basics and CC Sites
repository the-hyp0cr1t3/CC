# Competitive coding sites

𝐂𝐎𝐃𝐄𝐅𝐎𝐑𝐂𝐄𝐒

While there are a few good sites for contests , the main site I'd recommend would be CodeForces.

Here's a short writeup on how CodeForces style contests work :

There are 5-8 problems (generally 6) in (mostly) increasing order of difficulty.
There is max defined number of points per problem, also generally increasing (say 250 for A, 500 for B, 750/1000 for C, etc ).
As time passes, the score reduces at a rate of n/250 points per minute , where n is the total number of points for a problem. For example submitting A after

1 min - 498 points
2 mins - 496 points
5 mins - 490 points

On submitting your code , it is run and output is checked for 10-20 'test cases', if it passes all you get 'pretests passed' and you'll be awarded (temporary*) points and shown your approx rank in the contest at that moment.

However your program may not pass pretests in some cases :

𝟏.) WA - Wrong answer - your program gave the wrong answer for a test case

𝟐.) Runtime error - Your program did something not allowed in your language(Division by 0 , accessing an array index that is out of bounds , etc.).

𝟑.) TLE - Time limit exceed - your program exceeded the time limit mentioned in the question - try improving the time complexity of your code.

𝟒.) Memory limit exceeded - your program exceeded the memory limit mentioned in the question - try using less arrays,vectors,sets,maps or similar.

𝟓.) Compilation error - exactly what it states, try compiling on your system , find the error and fix it. ENSURE YOU ARE USING THE CORRECT COMPILER ON CODEFORCES(as in if you use MinGW/g++ <version> locally select GNU g++ <version> on CodeForces)

Now it is to be noted in most contests, a WA / TLE / Runtime error /memory limit exceeded will cost you 50 points to the final points earned on correct submission.
However if the error is on test 1 or in the case of a compilation error , no points will be deducted.

Example :

Submission at 4 mins : 492
Submission at 10 mins : 480
Submission at 4 mins with 1 wrong submission : 442

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
