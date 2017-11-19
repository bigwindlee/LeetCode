<B>思路</B>

  1）回溯法；本题的要点在于

  2）combinationSum3_0中可被优化的点：
    ① visit []bool 可被优化掉，注意backtrack_1()函数中 start 参数的使用；
    ② depth 参数可以把优化掉，通过 k 值的递减；
    ③ duplicate path 可以被优化掉；使用 append([]int{}, path...) 同样可以复制 path slice；

<B>216. Combination Sum III</B>
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
