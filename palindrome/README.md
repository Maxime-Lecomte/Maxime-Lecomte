# Palindrome

Hi ! here is the palindrome the goal of this project is to find such iterated reversal palindromes, and the smallest number of iterations, in order to get a palindromic number, given the constraints on this number of iterations.

![Image of -h](https://raw.githubusercontent.com/Maxime-Lecomte/Maxime-Lecomte/main/image/palindrome-h.png)

# First flag : -n

A palindrome is a word or a number which reads the same backward or forward (that is for numbers, numbers invariant when reversed).
A n-iteration turnover palindrome is a number which leads to a palindrome after n iterations of the following procedure:
1. reverse the number,
2. add both the number and its reversal to obtain a new number,
3. iterate from the first step until you get a palindromic number.

![Image of -h](https://raw.githubusercontent.com/Maxime-Lecomte/Maxime-Lecomte/main/image/palindrome-n.png)

# Second flag : -p
the goal of -p is to start from 1 and for each digit we must use the -n method until reaching the final digit
![Image of -h](https://raw.githubusercontent.com/Maxime-Lecomte/Maxime-Lecomte/main/image/palindrome-p.png)
## other flags

-imin n : set the min iteration at n
-imax n : set the max iteration at n
-b n : set the base at n