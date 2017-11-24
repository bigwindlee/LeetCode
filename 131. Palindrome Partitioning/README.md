<B>思路</B><br/>
1）典型的回溯法；第一个维度是第一刀下去切片的大小变化范围[1, len(s)]；第二个维度是继续往下切直到s为空；



<B>131. Palindrome Partitioning</B><br/>
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
