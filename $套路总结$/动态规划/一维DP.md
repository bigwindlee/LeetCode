|LeetCode|要点|
|-----------------------------|-----------------------------|
|[70. 爬楼梯][github-leetcode-0070]|爬到第 i 个台阶的方法有两种：从第 i-1 个台阶爬一步；从第 i-2 个台阶爬两步；|
|[91. 解码方法][github-leetcode-0091]|本题其实是“爬楼梯”的一种特殊形式，dp[i] = dp[i-1] + dp[i-2] 在部分情况下成立。|
|[213. 打家劫舍 II][github-leetcode-0213]|dp[i]表示前i家被偷窃的最高金额；把nums[0]是否被劫的情况分开来处理；|
|[403. 青蛙过河][github-leetcode-0403]|对于每块石头，如果下一跳有效，则更新下一块石头上能跳的步数（k-1, k, k+1）。|
|LCR 127. 跳跃训练|跳到第 i 个格子的方法有两种：从第 i-1 个格子跳一步；从第 i-2 个格子跳两步；|











[github-leetcode-0070]: ../../0070.%20Climbing%20Stairs/0070_climbStairs.h
[github-leetcode-0091]: ../../0091.%20Decode%20Ways/0091_numDecodings.h
[github-leetcode-0403]: ../../0403.%20Frog%20Jump/0403_canCross.h
[github-leetcode-0213]: ../../0213.%20House%20Robber%20II/0213_rob.h
