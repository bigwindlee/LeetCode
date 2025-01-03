|LeetCode|要点|
|----------------|----------------|
|[5. 最长回文子串][github-leetcode-0005]|二维DP：注意填表的顺序：i从右下角向上走，j从左到右；区间内收；|
| [72. 编辑距离][github-leetcode-72] | `dp[i][j]`表示word1的前`i`个字符转换成word2的前`j`个字符所用的步数 |
|[174. 地下城游戏][github-leetcode-0174]|二维DP + 逆向推导；至少一点血量；|
|[647. 回文子串][github-leetcode647]|如果`s[i: j]`的首尾字符相同，那么它是不是回文，取决于它的子状态`s[i+1: j-1]`是不是回文。|
|[1092. 最短公共超序列][github-leetcode-1092]|dp[i][j]表示s的前i个字符和t的前j字符构成的最短公共超序列的长度|
|[1143. 最长公共子序列][github-leetcode1143]|`dp[i][j]` 表示字符串`text1`的前`i`个字符 和 `text2`的前`j`个字符的最长公共子序列的长度。|
|[1246. 删除回文子数组][github-leetcode-1246]|区间DP：分别分成长度为1/2/3的区间进行讨论|
|[1312. 成为回文串的最少插入次数][github-leetcode1312]|定义 dp[i][j] 为：把子串 s[i...j] 转换为回文串所需的最少插入次数。|

## 什么是区间 DP？

区间 DP（Interval DP）是一类动态规划问题，主要用于处理涉及子区间或子数组的最优解问题。通常，问题要求我们对一个序列的某个子区间进行操作，而通过递归地解决较小子区间的问题，可以推导出较大子区间的最优解。


从整体与部分的角度考虑，区间DP是怎样定义子状态的？通过区间内收。


以回文子串为例：如果`s[i: j]`为回文，那么首尾各去掉一个字符，`s[i+1: j-1]`也是回文；或者说，在回文串`s[i+1: j-1]`首尾各添加一个相同的字符，也构成回文。递推关系建立！

## 区间 DP 的特征

1. **状态表示：**
   - 区间 DP 的状态通常用 `dp[i][j]` 表示，表示从序列索引 `i` 到 `j` 这一子区间的最优解。`i` 和 `j` 表示区间的左右边界。

2. **状态转移：**
   - `dp[i][j]` 的计算通常依赖于更小的区间（区间内收），例如 `dp[i+1][j]` 或 `dp[i][j-1]`，甚至 `dp[i+1][j-1]`。通过较小区间的解来推导较大区间的解。

3. **填表顺序：**
   - 区间 DP 需要从小区间向大区间进行转移。通常是从长度较短的区间开始填充 DP 表格，从而在计算较大区间时能依赖之前的计算结果。
   - 从二维dp矩阵的图形来看，`dp[i][j]`的子状态通常位于`[i, j]`小方格的左边、下边、左下边。这是因为`[i, j]`区间内收，导致i增大，j减小。

4. **边界条件：**
   - 通常情况下，边界条件是最小的区间，比如长度为 1 的子区间。

## 解答这类问题的核心要点

1. **状态定义清晰：**
   - 需要明确 `dp[i][j]` 的含义。一般它表示的是某个区间 `[i, j]` 的最优解或者该区间的一些特定性质（如是否为回文）。

2. **合理地定义转移关系：**
   - 通过已知的较小区间来推导较大区间的状态。思考从区间 `[i+1][j]`、`[i][j-1]` 或 `[i+1][j-1]` 如何推导出 `dp[i][j]`。

3. **正确地处理区间的遍历顺序：**
   - 一般先处理较短区间，再处理较长区间。常见的做法是从区间的左端点 `i` 开始遍历，然后通过逐渐增大区间长度来填表。

## 区间 DP 的应用场景

区间 DP 通常用于解决需要在一个区间上进行操作或判断的问题，包括但不限于：
- **回文相关问题**：如回文子串、回文子序列等。
- **合并问题**：如石子合并问题，涉及区间内元素合并的最优成本计算。
- **最优策略问题**：如最优二叉搜索树问题。
- **括号匹配问题**：涉及匹配和合并区间的动态规划问题。

## LeetCode 中的区间 DP 问题

以下是一些属于“区间 DP”类型的 LeetCode 题目：

1. **[647. 回文子串](https://leetcode.cn/problems/palindromic-substrings/)**  
   通过区间 DP 判断每个子串是否是回文，从而统计回文子串的数量。

2. **[516. 最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence/)**  
   通过 DP 计算一个序列的最长回文子序列。

3. **[312. 戳气球](https://leetcode.cn/problems/burst-balloons/)**  
   通过 DP 在一个区间内进行操作，并求出戳破气球能获得的最大分数。

4. **[375. 猜数字大小 II](https://leetcode.cn/problems/guess-number-higher-or-lower-ii/)**  
   在区间内通过二分法寻找最优策略的 DP 问题。

5. **[1000. 合并石头的最低成本](https://leetcode.cn/problems/minimum-cost-to-merge-stones/)**  
   在区间上进行合并操作，计算出最小合并成本。

6. **[132. 分割回文串 II](https://leetcode.cn/problems/palindrome-partitioning-ii/)**  
   寻找最少的切割次数，使得每一部分都是回文。

## 总结

区间 DP 主要用于处理子区间或子数组的优化问题，问题往往依赖于对较小区间的解来推导出较大区间的解。通过合理的状态转移和边界处理，可以高效解决涉及区间的动态规划问题。


[github-leetcode-0005]: ../../0005.%20Longest%20Palindromic%20Substring/LongestPalindrome.cpp
[github-leetcode-72]: ../../0072.%20Edit%20Distance/0072_minDistance.h
[github-leetcode-0174]: ../../0174.%20Dungeon%20Game/0174_calculateMinimumHP.h
[github-leetcode647]: https://github.com/bigwindlee/LeetCode/blob/master/0647.%20Palindromic%20Substrings/0647_countSubstrings.h
[github-leetcode1143]: https://github.com/bigwindlee/LeetCode/tree/master/1143.%20Longest%20Common%20Subsequence
[github-leetcode1312]: https://github.com/bigwindlee/LeetCode/blob/master/1312.%20Minimum%20Insertion%20Steps/1312_minInsertions.h
[github-leetcode-1246]: ../../1246.%20Palindrome%20Removal/1246_minimumMoves.h
[github-leetcode-1092]: ../../1092.%20Shortest%20Common%20Supersequence/1092_shortestCommonSupersequence.h
