|LeetCode|要点|
|--------------------------------|--------------------------------|
|[416. 分割等和子集][github-leetcode-0416]|01背包/状压DP：求一个`静态的和`是否可达（只有2种状态）的问题；|




## 什么是状态压缩动态规划（状压 DP）？

状态压缩动态规划（State Compression Dynamic Programming，简称状压 DP）是一种将状态表示为二进制位的方法，用于处理多个子问题组合的动态规划技巧。通过使用一个整数的二进制位来表示每个元素的选取状态，状压 DP 可以大大减少状态的数量，进而减少时间和空间复杂度。

例如：在有 `n` 个元素的集合中，可以用一个长度为 `n` 的二进制数来表示每个子集的选取状态。`1` 表示选中该元素，`0` 表示未选中，从而用一个整数来表示一种状态。

## 状压 DP 适合用来解决什么样的问题？

状态压缩 DP 适合解决以下类型的问题：

1. **子集选择问题**：需要判断哪些元素组合在一起满足某些条件。比如经典的子集和问题和集合划分问题。
2. **组合问题**：状态可以通过组合不同的选择来形成。比如旅行商问题（TSP）可以使用状压 DP 进行状态表示。
3. **多重约束问题**：可以用二进制位表示多个条件的满足情况。例如多种物品组合成一个方案的情况。

状态压缩 DP 的特点在于：
- **适合元素数量较少的情况**：因为状态数为 `2^n`，当 `n` 较大时状态数会增长迅速，适合处理 `n <= 20` 左右的情况。
- **适合状态可以表示为二进制组合的情况**：如果问题可以用一个二进制数的每个位表示一个选择，那么状压 DP 通常是有效的。

## 状压 DP 的核心要点

使用状态压缩 DP 的核心要点有以下几个：

1. **状态表示**：使用一个整数的二进制表示来存储多个元素的选取状态。例如，对应每个二进制数位，`1` 表示选中该元素，`0` 表示未选中。
  
2. **状态转移**：通常使用 `dp[mask]` 数组，其中 `mask` 是二进制数，表示一种选取状态。通过逐位遍历或位运算来进行状态转移。常用操作包括：
   - `mask | (1 << i)`：表示选取第 `i` 个元素。
   - `mask & ~(1 << i)`：表示取消选取第 `i` 个元素。
   
3. **初始状态与终止条件**：根据问题定义设定初始状态，比如空集的状态 `mask = 0`，并根据问题的具体目标设置终止条件。

4. **压缩空间**：状态压缩 DP 利用位操作和整数数组实现紧凑的存储和转移，有效地减少空间和时间复杂度。

## LeetCode 中的相关题目

以下是一些 LeetCode 中常见的与状态压缩 DP 相关的问题：

1. **[78. 子集 (Subsets)](https://leetcode.com/problems/subsets/)**
   - 使用二进制数表示每个元素的选取状态，生成所有可能的子集。

2. **[698. 划分为k个相等的子集 (Partition to K Equal Sum Subsets)](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)**
   - 用状态压缩表示每个元素是否已被分配到某个子集中，通过 DP 检查是否可以将数组划分为和相等的 `k` 个子集。

3. **[691. 贴纸拼词 (Stickers to Spell Word)](https://leetcode.com/problems/stickers-to-spell-word/)**
   - 给定贴纸和单词，要求使用最少的贴纸拼成该单词。可以用状态压缩来表示每个字符的选取情况，并通过 DP 计算最小贴纸数。

4. **[1125. 最小的必要团队 (Smallest Sufficient Team)](https://leetcode.com/problems/smallest-sufficient-team/)**
   - 找到满足所有技能的最小团队。可以用二进制表示技能组合，通过 DP 和状态压缩来确定最小团队。

5. **[137. 参加考试的最大学生数 (Maximum Students Taking Exam)](https://leetcode.com/problems/maximum-students-taking-exam/)**
   - 将教室的座位排列转换为二进制状态，通过状态压缩 DP 优化座位安排。

6. **[1434. 每个人戴不同帽子的方案数 (Number of Ways to Wear Different Hats to Each Other)](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/)**
   - 给定帽子和人，通过状态压缩 DP 表示每个人的帽子组合。

7. **[1349. 参加考试的最大学生数 (Maximum Students Taking Exam)](https://leetcode.com/problems/maximum-students-taking-exam/)**
   - 通过座位二进制状态来表示学生是否可以就坐，利用状态压缩和 DP 解决冲突安排的问题。

这些题目广泛应用了状态压缩 DP 技巧，有些使用了位运算，有些则结合 DP 状态表示和压缩技术来进行高效的解答。


[github-leetcode-0416]: ../../0416.%20Partition%20Equal%20Subset%20Sum/0416_canPartition.h
