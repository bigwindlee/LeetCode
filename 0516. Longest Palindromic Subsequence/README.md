子序列问题本身就相对子串、子数组更困难一些，因为前者是不连续的序列，而后两者是连续的，就算穷举你都不一定会，更别说求解相关的算法问题了。
一般来说，这类问题都是让你求一个最长子序列，因为最短子序列就是一个字符嘛，没啥可问的。一旦涉及到子序列和最值，那几乎可以肯定，考察的是动态规划技巧，时间复杂度一般都是 O(n^2)。
原因很简单，你想想一个字符串，它的子序列有多少种可能？起码是指数级的吧，这种情况下，不用动态规划技巧，还想怎么着？



为了解决 LeetCode 第 516 题 “最长回文子序列”，我们可以采用动态规划的方法。动态规划的基本思想是，对于字符串 `s`，使用一个二维数组 `dp` 来存储任意子字符串 `s[i...j]` 中最长回文子序列的长度。

### 解题思路

- **动态规划定义**：`dp[i][j]` 表示子串 `s[i...j]` 中最长回文子序列的长度。

- **转移方程**：
  - 如果 `s[i] == s[j]`，则 `dp[i][j] = dp[i+1][j-1] + 2`。
  - 如果 `s[i] != s[j]`，则 `dp[i][j] = max(dp[i+1][j], dp[i][j-1])`.

- **初始化**：单个字符的最长回文子序列长度为 1，即对所有 `i`，`dp[i][i] = 1`。

- **计算顺序**：从底部向上填充 `dp` 表，即从字符串的末尾开始向前计算。

![Longest Palindromic Subsequence](https://github.com/bigwindlee/LeetCode/blob/master/0516.%20Longest%20Palindromic%20Subsequence/images/0516_01.jpg "Longest Palindromic Subsequence Example")
![Longest Palindromic Subsequence Example 2](https://github.com/bigwindlee/LeetCode/blob/master/0516.%20Longest%20Palindromic%20Subsequence/images/0516_02.jpg "Longest Palindromic Subsequence Example 2")


```cpp
int longestPalindromeSubseq(string s)
{
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n));

	// 初始化，单字符的回文子序列长度是1
	for (int i = 0; i < n; ++i) {
		dp[i][i] = 1;
	}

	// 从底部向上，从左到右填表
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j - 1] + 2; // 左下角的方块 + 2
			} else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // 左边的方块和下边的方块取大的那个
			}
		}
	}

	return dp[0][n - 1];
}
```
### 代码解释

- **`dp` 数组的大小**：`dp` 数组的大小为 `n x n`，其中 `n` 是字符串 `s` 的长度。
- **初始化**：我们首先初始化每个单个字符的回文长度为 1。
- **循环计算**：接下来，使用两层循环，从字符串的末尾开始向前逐个计算每个子字符串的最长回文子序列长度。
- **最终结果**：最终结果存储在 `dp[0][n-1]` 中，表示整个字符串的最长回文子序列长度。

这种方法的时间复杂度为 O(n^2)，空间复杂度也是 O(n^2)，适合处理长度达到 1000 的字符串。这个动态规划方法不仅解决了问题，而且可以为类似问题提供通用的框架。
