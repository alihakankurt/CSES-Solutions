# Introductory Problems


## [Weird Algorithm](https://cses.fi/problemset/task/1068)

This problem is self-explanatory and has straightforward solution. The only thing to keep in mind is to use `64-bit` integer type to avoid overflow since the number can be quite large.


## [Missing Number](https://cses.fi/problemset/task/1083)

There are multiple ways to solve this problem.

First one is the starightforward solution where we can iterate over the given numbers and store them in a set. Then, we can iterate over the first `n` natural numbers and check whether the number is in the set. If not, we can return the number.

The second solution is to subtract each number from the sum of first n natural numbers. The remaining value will be the missing number. This solution is more efficient than the first one since it does not require extra space.

The third (and the my favorite) solution is to calculate the XOR of all the numbers in the array and first n natural numbers. Since the XOR of same numbers is `0`, the duplicate numbers will eliminate each other and the remaining XOR value will be the missing one.


## [Repetitions](https://cses.fi/problemset/task/1069)

This is a typical sliding window problem. We keep track of maximum length of same characters so far in a variable. Then, we iterate over the DNA sequence with two pointers: one for the start of the window and the other for the end of it.

Whenever we reach the end of the DNA sequence or encounter a different character from the one in the current subsequence, we update the result with the length of the current subsequence and restart a new one from the current position.


## [Increasing Array](https://cses.fi/problemset/task/1094)

This problem is also straightforward. Since every element in the array must be at least as large as the previous one, we can iterate over the array and check whether the current element is lesser than the previous one. If so, we can add difference to the operation count and assign the previous element to the current one. This ensures that the every element is at least as large as the previous one.


## [Permutations](https://cses.fi/problemset/task/1070)

We need to ensure that there is no two consecutive natural numbers are placed next to each other. To achieve this, we can arrange the numbers such that difference between any adjacent numbers is minimum possible, which is `2`.

This observation leads that we can place odd and even numbers up to `n` seperatly to the permutation array. But for `n = 4`, we cannot put odd numbers first because the result will be `1 3 2 4` which violates the condition of beautiful permutation. So, we can always put even numbers first and then put odd ones. Also, for `n = 2` and `n = 3` there is no solution either way, so we can print `NO SOLUTION` for these cases.


## [Number Spiral](https://cses.fi/problemset/task/1071)

Since the `y` and `x` values of each query may be very large in this problem, generating all possible values of spiral grid is inefficient. In fact, we can calculate the value of the cell in the spiral grid directly and it is just a few operations in constant time.

If we look carefully, we can see that the values in the diagonal form a pattern, because they do not depend on the direction of the spiral. The diagonal value in the `k`-th spiral can be calculated by the `k * (k - 1) + 1` formula, but in order to use it, we must know the index of spiral we are looking for. For each query, we already know which row and column we are processing, so if we take the maximum of `y` and `x` value, it should give us the spiral index. After this, we can calculate the value on the diagonal of the current spiral.

Finally, we should add an offset to the diagonal value. Since increase and decrease directions of odd and even indexed spirals are opposite, we can calculate their offset values by these: `y - x` and `x - y`. We can use the same maximum value from the previous operation to check whether the spiral has an odd or even index.


## [Two Knights](https://cses.fi/problemset/task/1072)

To answer this problem, we can count the number of all possible positions where two knights can be placed on a board, then subtract the attack positions from it.

The number of all possible positions of a board with `x` cells can be calculated using the `x * (x - 1) / 2` formula.

Next, we need to get the number of attack positions for the knights. Since knight moves do not depend on direction, we can calculate the attack positions for one side and then multiply it by `4` to get the total number of attack positions.

To get the attack positions for one side, we can count the number of `2`x`1` boxes that match the knight's moves. Each of these boxes represents a potential attack position for a knight. The total number of such boxes is `(n - 1) * (n - 2)` for a `n`x`n` board.

Finally, we can subtract the attack positions from the total number of possible positions to get the result.


## [Two Sets](https://cses.fi/problemset/task/1092)

We can first calculate the sum of the first `n` natural numbers and check whether it is divisible by `2`. If not, we can print `NO` since it is impossible to divide the numbers into two equal sum sets. Otherwise, we can continue to solve the problem.

Since the sum of numbers with the same index from the beginning and the end is always equal to `n + 1`, we can put these pairs into the same set. This idea also gives us the count of numbers in each set. The first one will have `n / 2` elements, and the second one will have `(n + 1) / 2` elements ('cause of odd cases).

My way of doing this is to determine two limits that split the numbers into three intervals: `1` to `limit1`, `limit1 + 1` to 'limit2', and `limit2 + 1` to `n`. The pairs of the first set can be found in the first and last intervals separately, and the pairs of the second set can be found in the middle one together. This way, we can print the numbers correctly without any additional storage.

The last thing to note is that when `n` is odd, we need to calculate the limits for `n - 1` instead of `n` to ensure that the sum of the numbers in the sets is equal.


## [Bit Strings](https://cses.fi/problemset/task/1617)

This problem is very simple. The number of bit strings of length `n` is `2^n`. But since the result can be very large, we cannot shift `1` to the left `n` times. Instead, we can calculate the result by taking the modulo of `2^n` with `10^9 + 7` after each multiplication, just like the modular exponentiation algorithm.


## [Trailing Zeros](https://cses.fi/problemset/task/1618)

In this problem, we cannot calculate the `n!` directly because it will be very large and will not fit into any integer type. Instead, we can calculate the number of trailing zeros in the factorial of `n` using divisibility rules.

If we count the number of `2` and `5` in the prime factorization of each number from `1` to `n`, the minimum of these two values will give us the number of trailing zeros in `n!`. But since the number of `5` is always less than the number of `2`, we can just look for the number of `5` in the prime factorization of each number from `1` to `n`.


## [Coin Piles](https://cses.fi/problemset/task/1754)

In order to empty each pile, the total number of coins must be divisible by `3` so that we can remove the coins from the piles because we can remove `3` coins in total for each move. Also, the number of coins in each pile must be at least `1/3` of the total number of coins since we can remove `1` and `2` coins from piles exchangeably.


## [Palindrome Reorder](https://cses.fi/problemset/task/1755)

This problem involves counting the number of each character in the given string along with the number of odd counts. If the number of odd counts is greater than the parity of the string length, it is impossible to create a palindrome. Otherwise, we can create a palindrome by placing the characters in the correct order.

To rearrange the characters as a palindrome, we can use the two-pointer technique: one for the start and the other for the end of the string. We can iterate over the letters and place the characters with counts greater than `2`, in the positions pointed by start and end pointers while decrementing the count. Then we should advance the pointers. If there is a character with an odd count, we can place it in the middle of the string.


## [Gray Code](https://cses.fi/problemset/task/2205)

In Gray code, each number differs from the previous number by only one bit. The formula for generating `i`-th number of the `n`-bit Gray code is XORing `i` with `i` shifted right by `1`. We can generate the Gray code numbers by iterating over the numbers from `0` to `2^n - 1` and applying the formula to each number.


## [Tower of Hanoi](https://cses.fi/problemset/task/2165)

Actually this problem has a recursive solution but I used binary counting and bitwise operations to solve it iteratively. The idea is to count from `0` to `2^n - 1` and move the disk with index which is first different bit from the previous number. If the total number of disks is even, the direction of the movement is clockwise, otherwise it is counterclockwise. This way, we can move disks from the left stack to the right stack in the minimum number of moves.


## [Creating Strings](https://cses.fi/problemset/task/1622)

To generate all different strings using the characters of the original string, we can use a permutation algorithm. One approach is to sort the string and then use a built-in function like `std::next_permutation` in C++. However, we can also implement our own permutation function.

Here's how it works:
1. Iterate over each index from `n - 2` to `0`, where `n` is the length of the string.
2. For each index, compare the character at that index with the characters from `n - 1` to the index.
3. If there is a character greater than the character at the index, swap these characters.
4. After swapping, reverse the substring from the next index to the end of the string.

By following these steps, we can generate all different strings by permuting the characters of the original string.


## [Apple Division](https://cses.fi/problemset/task/1623)

Since the number of elements in the array is at most `20`, we have time to calculate the sum of each subset. We can use bitmasking to iterate over all possible subsets of the array. We can store the maximum weight that is less than or equal to half of the total weight of the apples in a variable and update it while iterating over the subsets. Finally, we can get the minimum difference by subtracting twice the maximum weight from the total weight of the apples.


## [Chessboard and Queens](https://cses.fi/problemset/task/1624)

We can count the number of safe positions for the queens by using a backtracking algorithm, specifically a Depth-First Search (DFS). If we have to place `N` queens on a `N`x`N` chessboard, every rank, file, and diagonal should have at most one queen.

To check whether a position is safe to place a queen in the search function, we can maintain boolean arrays to track occupied ranks, files, and diagonals. This allows us to avoid placing queens in unsafe positions and accurately count the number of safe positions for the queens.

Instead of tracking both occupied ranks and files simultaneously, we can optimize the algorithm by using a single array to track one of them and incrementally pass the other to the search function. This reduces the space complexity of the algorithm.

When the depth of the search reaches `N`, we can return `1` to indicate that a safe position for the queens has been found. By accumulating the return values of the recursive calls, we can determine the total number of safe positions for the queens on the chessboard.


## [Digit Queries](https://cses.fi/problemset/task/2431)

We cannot generate the string of digits to answer each query because the upper limit of `k` is `10^18`. So, we need to find the actual number that owns the `k`-th digit. We can achieve this by grouping the numbers, by their digit count.

If we look at the numbers with `1` digits, there are `9` numbers with `1` digits, `90` numbers with `2` digits, `900` numbers with `3` digits, and so on. Also, the last digit index of the numbers with `n` digits is `9 * n * 10^(n - 1)`. By using this information, we can find the actual number that owns the `k`-th digit.

First, we need to find the range of the numbers that have the same digit count as the `k`-th digit. Then, we can find the target number by dividing the `k` with the digit count and adding the first number in the range. Finally, we can find the `k`-th digit of the digit string by dividing and modulo operations on the target number.


## [Grid Paths](https://cses.fi/problemset/task/1625)

Similar to the `Chessboard and Queens` problem, we can use a Depth-First Search function to count each valid paths from top-left corner to the bottom-left corner.

We can start by create the initial version of the function. This function checks each direction whether it is moveable or not and, add count of the number of the paths in that direction into the current result. We can maintain a boolean matrix to track visited cells.

The initial version of the search functions runs very slow, because there can be cycles since we can move in all four directions. So, we should optimize the search function a little bit before submission.

First, we can check whether we reach the target cell early, and if so, we can terminate the search without going any deeper. This is a small one but efficient. Then, we can remove boundary checks by extending the visited matrix by one in each direction. This is a trade-off between space and time.

And as the final optimization, we can check whether the direction we move split the grid into two parts that we cannot reach the one from the other. If so, then we cannot make the move. This one especially a very good optimization and drops the search time under `1` second, so we can pass the testcases without time limit.
