# 动态规划 vs 滑动窗口：如何区分？

**动态规划**和**滑动窗口**都是常见的算法技巧，尤其是在处理数组或字符串相关的问题时。两者有时会被混淆，因为它们可以解决类似的题目，比如“连续子数组”的问题。但它们的适用场景和核心思想是不同的。

## 1. 核心思想的区别：

- **动态规划**：
  - 动态规划的核心思想是**通过子问题的解推导出更大问题的解**，每一步决策依赖于之前的状态，通常使用一个数组或几个变量来存储中间状态，逐步构建解决方案。
  - 动态规划适合**需要维护一个与过去状态相关的值**的问题，通常有明确的递推关系。
  - **举例**：在 **最大子数组和（LeetCode 53）** 问题中，状态转移方程为 `dp[i] = max(nums[i], dp[i-1] + nums[i])`，表示当前的最大子数组和要么是加入前一个子数组，要么重新开始。

- **滑动窗口**：
  - 滑动窗口的核心思想是**通过移动窗口的起点和终点来动态调整区间**，适合处理那些可以通过线性扫描调整窗口边界并直接得到答案的问题。
  - 滑动窗口通常用于**在一个数组或字符串中找到满足条件的子区间或子串**，问题的性质是随着窗口的扩展或缩小，解的状态也随之改变。
  - **举例**：在 **和为 K 的子数组（LeetCode 560）**，我们利用前缀和可以看作是一种特殊形式的滑动窗口，只不过通过哈希表来记录前缀和变化。

## 2. 何时使用动态规划：
   - 问题中每一步的决策依赖于**之前的状态**，例如要维护最大或最小值、某种累计和等。
   - 问题具有明确的递推关系，比如**状态转移方程**。
   - 解决方案通常是通过遍历数组或字符串并逐步更新状态。
   - **典型问题**：
     - **LeetCode 53: 最大子数组和**：需要在每一步维护以当前元素结尾的最大子数组和。
     - **LeetCode 152: 乘积最大子数组**：需要同时维护最大和最小的乘积。
     - **LeetCode 918: 环形子数组的最大和**：通过动态规划维护最大子数组和与最小子数组和。

## 3. 何时使用滑动窗口：
   - 你需要在一个区间上查找满足条件的子区间，当区间不满足条件时，可以通过**移动窗口的左右边界**来调整子区间。
   - 问题往往涉及**窗口大小的动态调整**，不需要依赖于前一个位置的状态。
   - **滑动窗口通常适用于查找子数组、子串的问题**，要求在子区间或子串中满足某个特定的条件（比如和、乘积、某种字符分布等）。
   - **典型问题**：
     - **LeetCode 3: 无重复字符的最长子串**：通过维护一个滑动窗口记录子串的字符分布，并动态调整窗口的左边界来找到最长的无重复子串。
     - **LeetCode 209: 长度最小的子数组**：通过滑动窗口找到和至少为 `s` 的最小长度子数组。
     - **LeetCode 438: 找到字符串中所有字母异位词**：使用滑动窗口检查一个字符串的所有子串是否为给定字符串的异位词。

## 4. 具体例子对比：

- **最大子数组和（LeetCode 53）**：
  - **动态规划**解法：维护一个 `currSum` 来记录当前子数组的和，如果 `currSum` 小于 0，就重新开始计算。
  - **滑动窗口**不适用：因为我们需要累加所有元素，不能通过单纯调整窗口大小来解决问题。

- **和为 K 的子数组（LeetCode 560）**：
  - **动态规划**不适用：问题的本质是查找满足和为 K 的连续子数组，不能通过递推关系来解决。
  - **滑动窗口/前缀和**：通过维护前缀和，可以快速找到符合条件的子数组。

- **无重复字符的最长子串（LeetCode 3）**：
  - **动态规划**不适用：问题需要动态调整窗口来确保子串中没有重复字符。
  - **滑动窗口**：通过调整窗口的左右边界来维持当前子串的无重复性。

## 5. 动态规划与滑动窗口如何区分：
   - **动态规划**：问题有一个递推关系，当前状态依赖于前面的状态，每一步的解是基于之前的解构建出来的。
   - **滑动窗口**：问题可以通过移动窗口的边界来找到符合条件的解，窗口的大小和位置是动态变化的，通常不需要记录或依赖之前的状态。

## 6. 总结：
- **动态规划**适合处理那些需要维护**历史状态**或通过**递推关系**计算当前解的问题。它通常用于维护最大值、最小值、累计和等状态。
- **滑动窗口**适合那些需要动态调整区间的边界、并且可以通过**改变窗口的大小或位置**来找到解的问题。它常用于查找满足某些条件的子数组或子串。

通过问题的本质来选择算法：如果需要维护一个状态并且通过递推关系来更新，那可能更适合动态规划；如果问题需要查找一个动态变化的区间，则更适合滑动窗口。
