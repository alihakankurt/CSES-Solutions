# Sorting and Searching


## [Distinct Numbers](https://cses.fi/problemset/task/1621)

This problem is very simple to solve. Counting the number of first appearances of each value should give us the number of distinct values. This can be done by sorting and iterating over the given numbers and comparing them with the previous one.


## [Apartments](https://cses.fi/problemset/task/1084)

By sorting both the list of applicant desires and the list of actual sizes of apartments, we can ensure that the sizes are in close proximity to each other at the same index. This allows us to easily match each applicant with a suitable apartment using a two-pointer technique.

Here's how the two-pointer technique works: If the size of the current apartment is too small for the applicant, we can move to the next apartment by incrementing the apartment index. Similarly, if the size of the current apartment is too large for the applicant, we can move to the next applicant by incrementing the applicant index. However, if the size of the current apartment falls within the desired range of the applicant, we have found a match and can increment both indices.

Using this approach, we can efficiently match applicants with apartments based on their desired sizes, ensuring a fair and optimal allocation process.


## [Ferris Wheel](https://cses.fi/problemset/task/1090)

To minimize the number of needed gondolas, we should always look for putting two children into one gondola. This can be achieved by sorting the weights of the children and using the two-pointer technique: one for the minimum weight and the other for the maximum one.

We can check whether the sum of the minimum and maximum weights is less than or equal to the maximum allowed weight, and if so, we can put these two children into one gondola and advance the left and right pointers by one. Otherwise, we can always put the maximum weighted child since there can be a pair to the minimum weight. This process continues until there is no child left.


## [Concert Tickets](https://cses.fi/problemset/task/1091)

Since the order of the customers matters, we cannot solve this problem by sorting both the tickets and customers, then using the two-pointer method. But instead, we can use a binary search over the ticket prices after sorting them. This way, we can ensure that each customer gets the best ticket available at the time of their arrival, maximizing their price.

After sorting the tickets, we can iterate over the customers and use a binary search to find the best ticket available for each customer. If we find a ticket that is less than or equal to the customer's budget, we can give it to the current customer. Otherwise, the customer cannot get any tickets, and we can print `-1`. This way, we can maximize the revenue from ticket sales while ensuring that each customer gets a ticket within their budget.


## [Restaurant Customers](https://cses.fi/problemset/task/1619)

To get maximum customers at any time, we can split the arrival and departure times as events and sort them by their time. Then, we can iterate over the events and increment or decrement the current number of customers depending on the event type. By keeping track of the current number of customers, we can accumulate the maximum number of customers at any time. This approach allows us to efficiently calculate the maximum number of customers in the restaurant at any given time.


## [Movie Festival](https://cses.fi/problemset/task/1629)

By sorting the movies according to their end times and iterating over them to check whether we can watch them or not, we can maximize the number of movies we can watch in total. This check can be done by comparing the start time of the current movie with the end time of the last watched movie. If this condition is satisfied, we can increment the number of watched movies and update the last movie we watched to the current one.


## [Sum of Two Values](https://cses.fi/problemset/task/1640)

Here's another problem that can be solved using the two-pointer technique. By sorting the given numbers and using two pointers, one at the beginning and the other at the end of the sorted numbers, we can efficiently find two values that sum up to a given target value.

To do this, we can check whether the sum of the values at the two pointers is equal to the target value. If it is, we have found the two values that sum up to the target value. If the sum is less than the target value, we can increment the left pointer to increase the sum, and if the sum is greater than the target value, we can decrement the right pointer to decrease the sum. This process continues until we find the two values that sum up to the target value or determine that no such values exist.

The only problem here is that we need to keep track of the original positions of the numbers to print them correctly. This can be done by storing the original positions along with the numbers in a separate data structure before sorting the numbers.


## [Maximum Subarray Sum](https://cses.fi/problemset/task/1643)

This problem has straightforward solutions in cubic or quadratic time complexities, but the algorithm should be linear since the `n` can be `2 * 10^5`. Also, we cannot sort the array because the problem states that the subarray is a contiguous part of the original array. And for this reason, there is no need to store any elements in the data structure; we can just process them after reading.

We can achieve the goal of the problem by keeping track of two variables: the local maximum sum of the subarray that ends at the current index and the global maximum sum, which contains the greatest local sum. After we read the next value, we can update the local sum by the maximum of the current value and the sum of the current value plus the local sum of the previous index. Then we can update the global sum to the current local sum if the local sum is greater. When the iteration is done, the global sum will be the maximum subarray sum.


## [Stick Lengths](https://cses.fi/problemset/task/1074)

The best way to make a number sequence equal by incrementing or decrementing is to sum up the absolute differences between the sequence and the median of the sequence. The median is the middle element of the sorted sequence, so we can sort the given stick lengths and acquire the median. Then, we can iterate over the sequence and add the absolute difference between the median and the current stick length to the total operation cost. This way, we can minimize the total cost of making the stick lengths equal.


## [Missing Coin Sum](https://cses.fi/problemset/task/2183)

Let's start by examining the powers of `2` since we can represent every number in binary. In binary, each power of `2` comes after the last number that can be obtained with the previous ones. For example, if we have `1` and `2`, we can get the numbers up to `3`, and after that we need `4` to continue on the sequence. But what if we do not have `4` and the next value was `5`? Then we cannot generate `4` at any time using the given numbers. This approachs leads to us whenever we found a coin that is greater than the total coin sum plus `1`, the sum plus `1` is the missing coin sum. We can easily solve after this observation by sorting and iterating over the sorted coins.


## [Collecting Numbers](https://cses.fi/problemset/task/2216)

To solve this problem, we can store the positions of the numbers in an array with a size of `n + 1`, instead of the numbers themselves. Then, we can iterate numbers from `1` to `n` and check whether the current number's position is less than the next number's position. If it is, we can collect the next number with the same round of the current number. Otherwise, we must start a new round in order to collect the next number. This way, we can efficiently calculate the number of rounds needed to collect all the numbers in the given sequence.


## [Collecting Numbers II](https://cses.fi/problemset/task/2217)

This problem has the same logic as the previous one, but with an additional operation that can change the positions of the numbers. To handle this, we need to store the numbers also in an array to access them by positions. After processing the input, we can count the initial number of rounds needed to collect all the numbers in the given sequence, as we did in the previous problem. Then, we can start processing the updates and change the positions and the numbers accordingly. In order to recalculate the number of rounds, we can use the same logic but there is not need to start from the beginning. We can just check for the numbers affected by the operation and update the number of rounds by comparing previous and next numbers' positions with the current number's old and new positions. As a final note, we can create the position and number arrays with the size of `n + 2` to avoid any out-of-bounds conditions.


## [Playlist](https://cses.fi/problemset/task/1141)

To find the longest sequence of unique songs in the playlist, we can use the sliding window technique. We can start by iterating over the playlist and incrementing the end pointer of the window. If we encounter a song that is already in the window, we can update the longest sequence length if the current window length is greater than the previous longest sequence length. After that, we can increment the start pointer of the window until the song is removed from the window. But instead of moving the start pointer one by one, we can directly jump to the correct position by storing the last position of each song in the playlist using a map. This way, we can efficiently find the longest sequence of unique songs in the playlist.


## [Towers](https://cses.fi/problemset/task/1073)

To minimize the number of towers needed to be built, we can simulate the process of placing the cubes. We can keep track of the cubes at the top of each tower in an array as sorted. Then, we can iterate over the cubes and look for a tower with the smallest cube that is greater than the current cube using binary search. If we find such a tower, we can update the tower with the current cube. Otherwise, there is no suitable tower for the current cube, and we can create a new tower with it. At the end of the iteration, the size of the tower array will be the minimum number of towers needed to be built.


## [Traffic Lights](https://cses.fi/problemset/task/1163)

To find the longest passage after adding a traffic light, we can get the previous and next traffic light positions. Then, we can remove the current distance from the previous to the next and add two new distances from the previous to the new light and from the new light to the next. Then, we can print the maximum value of the distances. We can use a map to store the distances between the traffic lights and an array to store the position of each break point, specifically sorted to allow binary search.


## [Josephus Problem I](https://cses.fi/problemset/task/2162)

The first version of the Josephus problem can be solved by simulating the process of removing and skipping the next person. We can use a queue to store the remaining children in the circle, and then we can loop until there is only one child left. In each iteration, we can remove the next child from the queue and add it to the end of the queue, then print the next child and remove it from the queue. Finally, we can print the last child remaining in the queue to complete the simulation.


## [Josephus Problem II](https://cses.fi/problemset/task/2163)

The second version of the Josephus problem introduces the number `k` which determines the number of children to skip before removing the next child. We cannot solve the problem using the previous solution because the number of remove and insert operations will be too big and this probably causes time limit exceeded. So, we need to optimize the remove and insert operation to reduce overall time complexity. This optimization can be achieved by using a red-black tree, a segment tree or a binary indexed tree to store the children in the circle. I personally prefer binary indexed tree because it is easier to implement.


## [Nested Ranges Check](https://cses.fi/problemset/task/2168)

To check whether ranges are nested or not, we can sort the ranges by their end points and then by their start points. Then, we can iterate over the ranges to check whether the current range contains any of the previous ranges by keeping track of a variable that stores the maximum start point to compare with the current range's start point. If the current range's start point is less than or equal to the maximum start point, then the current range contains a previous range; otherwise, we can update the maximum start point to the current one. We can apply the same strategy by iterating over the ranges in reverse order and keeping track of the minimum start point so far to check whether the current range is contained by any of the following ranges. This way, we can efficiently check whether the ranges are nested or not.


## [Nested Ranges Count](https://cses.fi/problemset/task/2169)

In this version of the problem, the logic is the same as the previous one. The number of start positions that are less than or equal to the current range's start position is the number of ranges that contain the current range. And the number of start positions that are greater than or equal to the current range's start position is the number of ranges that are contained by the current range. In order to get these values, we can use ordered sets or binary indexed trees to store the start positions and update the counts accordingly while iterating over the ranges. If we decide to use binary indexed trees, we must also assign a unique index to each start position to avoid large memory usage and gain better performance.


## [Room Allocation](https://cses.fi/problemset/task/1164)

To solve this problem, we can sort the customers by their arrival times and iterate over them to allocate new rooms or an existing room if previous customer's departure time is less than the current customer's arrival time. We can use a priority queue to store the departure times and allocated rooms sorted by the departure times. This way, we can efficiently allocate rooms to customers and minimize the number of rooms needed to accommodate all customers.


## [Factory Machines](https://cses.fi/problemset/task/1620)

To find the time required to produce `t` products, we can use binary search to find the minimum time. According to the constraints, the maximum time can be at most `10^18`. So, we can start searching between `0` and `10^18` and calculate the number of products that can be produced in the middle time. If the number of products is greater than or equal to the `t` products, we can update the answer and the upper bound of the search. Otherwise, we can update the lower bound of the search. This way, we can efficiently find the minimum time required to produce `t` products.


## [Tasks and Deadlines](https://cses.fi/problemset/task/1630)

This problem is not as difficult as it seems. To maximize the total reward, we should start the task with minimum duration first so that we can get the reward as soon as possible. But also, we should consider deadlines because if we finish the task after the deadline, we will get a penalty. So, we can sort the tasks by their durations, then by their deadlines. After that, we can iterate over the tasks and calculate the total reward by managing the current time and the total reward. This way, we can maximize the total reward by completing the tasks in the optimal order.


## [Reading Books](https://cses.fi/problemset/task/1631)

For this problem, if we let Kotivalo read all the books sorted by their reading times and have Justiina follow Kotivalo after reading the longest book, we can minimize the total time required to read all the books. There could be 2 outcomes: Kotivalo and Justiina finish reading at the same time, or Kotivalo finishes first. In the first case, the minimum total time will be the sum of the reading times, and in the second case, the minimum total time will be the maximum reading time multiplied by 2. We can calculate the result by just storing the total reading time and the maximum reading time without any additional data structures. So our answer will be the maximum of these two values.


## [Sum of Three Values](https://cses.fi/problemset/task/1641)

This problem is similar to the "Sum of Two Values" problem, but with an additional value to find. We can sort the given numbers and iterate over them to find the three values that sum up to the target value. To achieve this, we can fix the first value and use two pointers to find the other two values. We can increment the left pointer if the sum of the three values is less than the target value and decrement the right pointer if the sum is greater than the target value. This way, we can efficiently find whether there are three values that sum up to the target value or not. Also, we must store the original positions of the numbers to answer correctly.


## [Sum of Four Values](https://cses.fi/problemset/task/1642)

This is similar to the previous two problems, but with four values to find. We can apply the same solution by fixing the first two values with an additional `for` loop to get the answer.


## [Nearest Smaller Values](https://cses.fi/problemset/task/1645)

We can start by iterating the array in reverse order. In each iteration, we can check whether the current value is less than the previous ones. If it is, we can assign the current position as the nearest smaller value for all the previous values until we find a smaller value. We can achieve this by using a max-heap to store the previous values along with their positions. This way, we can efficiently find the nearest smaller value for each element in the array.


## [Subarray Sums I](https://cses.fi/problemset/task/1660)

To find the number of subarrays that sum up to a value, we can use the sliding window technique to iterate over the array and keep track of the current sum. We can add the current value to the current sum, and if the current sum exceeds the target value, we can remove the previous values from the current sum until it is less than or equal to the target value. Finally, we can check whether the current sum is equal to the target value and increment the count accordingly. This way, we can efficiently find the number of subarrays that sum up to the target value.


## [Subarray Sums II](https://cses.fi/problemset/task/1661)

The main difference between this problem and the previous one is that the numbers can be negative. So, we cannot use the sliding window technique because we could miss some subarrays. Instead, we can optimize the prefix sum approach by using a hash map to store the previous prefix sums and their counts. By iterating over the array and calculating the prefix sum in each step, we can check whether the current prefix sum minus the target value exists in the hash map. If it does, we can increment the count by the number of occurrences of that prefix sum. Then, we can update the hash map with the current prefix sum and its count. This way, we can efficiently find the number of subarrays that sum up to the target value even with negative numbers.


## [Subarray Divisibility](https://cses.fi/problemset/task/1662)

This problem can be solved by the same approach of `Subarray Sums II` but instead of working with prefix sum, we keep track of the remainder of the prefix sum. And by updating the hash map that we used to store the count of the remainders, we can get the number of subarrays that have the same remainder as the current prefix sum, and then we can use it to update our answer.


## [Distinct Values Subarrays II](https://cses.fi/problemset/task/2428)

For this problem, we can simply use the two-pointer technique and store the values in our subarray in a map with their number of occurrences. On every iteration, if our subarray has more distinct values than `k`, we can remove the numbers from the start until the subarray has less than or equal distinct values from `k`. At the end, we add the length of the subarray to the answer.


## [Array Division](https://cses.fi/problemset/task/1085)

In this problem, we should have that observation first. If we can divide the array into `k` or fewer subarrays with the maximum sum being less than or equal to a specific limit, then we can divide the array into `k` subarrays without increasing the maximum sum. So, our goal is to minimize that specific limit, and we can use binary search for it by assigning the `left` with the maximum number in the array and the `right` with the sum of the array.


## [Sliding Window Median](https://cses.fi/problemset/task/1076)

To find the median of a sliding window, we can use a balanced binary search tree to store the numbers in the current window. By maintaining two heaps, one for the lower half and one for the upper half of the current window, we can efficiently find the median in logarithmic time, which is the maximum of the lower half. The only tricky part of this problem is how to maintain the heaps and how to insert and delete the numbers from them.

The insertion operation goes like this: if the number is greater than the current median, we insert it into the upper heap. Otherwise, we insert it into the lower heap. After that, we need to check whether the heaps are balanced or not. If the count of the lower heap is greater than the upper heap by more than `1`, since the length of the window can be odd, we need to move the maximum of the lower heap to the upper heap. And if the count of the upper heap is greater than the lower heap, we need to move the minimum of the upper heap to the lower heap.

For the deletion operation, we can just check whether the number is in the lower heap or the upper heap. After that, we can remove it from the corresponding heap. Then, we need to check whether the count of the lower heap is greater than or equal to the upper heap. If not, we need to move the minimum of the upper heap to the lower heap.


## [Sliding Window Cost](https://cses.fi/problemset/task/1077)

This problem is nearly identical to the previous one; we should just store the sum of the lower heap and the upper heap to calculate the total cost of making all numbers equal. Then by subtracting the lower sum from the upper sum, we get the cost for the current window. Additionally, for windows that have odd lengths, we should add the median value to the cost.


## [Movie Festival II](https://cses.fi/problemset/task/1632)

In the second version of this problem, we have more than one person watching the movies. We can start just as before by sorting the movies according to their end times. Then we can store the end times of last-watched movies in a binary search tree so we can check whether a person can watch the current movie or not. We can maximize the number of movies that we can watch by assigning the new movie to the person with the greatest end value that can watch the movie.


## [Maximum Subarray Sum II](https://cses.fi/problemset/task/1644)

For the second version of this problem, we have minimum and maximum subarray length limits. We could try to solve this using the previous solution directly and additionally checking the subarray lengths, but this doesn't cover all the possible subarrays. Therefore, our solution will be incorrect for some cases.

Instead, we can start by building a prefix sum with given numbers so that we can query the sum of a range. Then, for each upper bound of the prefix sum, our goal is to find the lower bound such that its value is the minimum possible so we can get the maximum value for the current range. We can achieve that goal by using a binary search tree to store the prefix sums of the current range, but not all of them. Since we have a minimum length limit, we should only store the prefix sums that have a greater index than the current index minus the minimum length. We also should remove the prefix sums that have a greater index than the current index minus the maximum length. This way, we can keep track of the prefix sums that are valid for the current range.

While we iterate over prefix sums with the start index being the minimum limit, if the current prefix sum minus the minimum prefix sum that we can get from the binary search tree is greater than the answer, we can update it. This way, we can efficiently find the maximum subarray sum with the given length limits.
