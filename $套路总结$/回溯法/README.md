| LeetCode | 要点 |
| ----------- | ----------- |
| [17. 电话号码的字母组合][github-leetcode-0017] |第一维度：每个键盘数字对应的字母取值范围；第二维度：用path控制搜索深度；|
| 40. 组合总和 II | Title |
|[46. 全排列][github-leetcode-0046]| 每个数字只能用一次，所以需要一个used数组做标记。 |
|[47. 全排列 II][github-leetcode-0047]|回溯；重复数字不牵头；|
|[79. 单词搜索][github-leetcode-0079]|回溯：在回溯函数中标记本节点已被访问（设置为0）；|
|[93. 复原 IP 地址][github-leetcode-0093]|回溯：IP地址每节长度为1~3，对应3个搜索方向；|
|[140. 单词拆分 II][github-leetcode-0140]|记忆化DFS + 回溯|
|[526. 优美的排列][github-leetcode-0526]|经典回溯 + 全排列 + 剪枝 + backtrack返回值累加|
| LCR 083. 全排列 | 同[46. 全排列][github-leetcode-0046] |

## 回溯法简介
回溯法按深度优先策略搜索问题的解空间树。首先从根节点出发搜索解空间树，当算法搜索至解空间树的某一节点时，先利用剪枝函数判断该节点是否可行（即能得到问题的解）。如果不可行，则跳过对该节点为根的子树的搜索，逐层向其祖先节点回溯；否则，进入该子树，继续按深度优先策略搜索。


回溯法的基本行为是搜索，搜索过程使用剪枝函数来为了避免无效的搜索。剪枝函数包括两类：
1. 使用约束函数，剪去不满足约束条件的路径；
2. 使用限界函数，剪去不能得到最优解的路径。


问题的关键在于如何定义问题的解空间，转化成树（即解空间树）。解空间树分为两种：子集树和排列树。两种在算法结构和思路上大体相同。

## 何时使用回溯法

回溯法适用于以下类型的问题：

### 组合问题
- 当问题要求找出满足某种条件的所有可能的组合时，适用于组合总和、子集、排列等问题。
- **例子**：LeetCode上的“子集”、“排列”、“组合总和”系列问题。

### 划分问题
- 需要将数据（通常是字符串或数组）分割成满足特定条件的部分。
- **例子**：分割回文串、数组分割成k个相等的子集。

### 搜索问题
- 在一个复杂的结构（如图、矩阵、棋盘）中搜索满足特定条件的路径或解决方案，如棋盘问题（N皇后、解数独）和迷宫问题。

### 决策问题
- 需要做出一系列决策以达到目标，每个决策点都可能有多个选项，需要找出能成功达到目标的决策序列。
- **例子**：电话号码的字母组合、括号生成。

## 回溯法的特点
- **试错**：它尝试分步去解决一个问题。通过试错，回溯法尝试各种可能性，如果当前步骤失败，就回退到上一步或几步，然后尝试其他可能的选项。
- **递归实现**：回溯法通常通过递归函数来实现。
- **剪枝操作**：在递归过程中，及早地切断不可能的路径，这是提高回溯效率的关键步骤。

### 回溯法需要考虑的几个问题
- 2个维度分别是什么；解空间是否可以包含重复的candidate，解空间中的candidates是否是有序的；
- 2个维度是否可以分别优化；
  - 第1个维度用for循环实现，那么for循环的起点是否是变化的，是否可通过递归参数传递进来；
  - 第2个维度用递归实现，如何判定到达叶子节点（递归函数的出口）；如果是固定的深度则可通过depth递减来实现；如果是对candidates求和则可通过sum的递减来实现；
- isValid()函数的实现；尽量提前判断有效性；
- dfs()搜索是对path的收集是否可以优化；

### 举个例子
考虑“组合总和”问题，你需要找出所有可能的方式将给定的数字组合成目标数。这里，每一步你都有多种选择（可以选择数组中的任何数字），而每次选择后，你又面临着新的选择，直到达到目标数或超过目标数。如果超过目标数，就回退到之前的状态，尝试其他数字，这就是回溯的典型应用。

### 结论
回溯是一种**递归+撤销的穷举搜索**策略，按照选-试-不行就撤销（回退）再选的方式，尝试所有可能的路径，找到符合条件的解。

当你面对一个问题，需要探索所有可能的解决方案时，尤其是在解决方案涉及多个阶段的决策时，回溯法往往是一种有效的方法。它通过试错法来探索所有可能的解决方案，并利用剪枝来优化搜索过程，避免无效的探索。


[github-leetcode-0017]: ../../0017.%20Letter%20Combinations%20of%20a%20Phone%20Number/0017_letterCombinations.h
[github-leetcode-0046]: ../../0046.%20Permutations/0046_permute.h
[github-leetcode-0047]: ../../0047.%20Permutations%20II/0047_permuteUnique.h
[github-leetcode-0526]: ../../0526.%20Beautiful%20Arrangement/0526_countArrangement.h
[github-leetcode-0140]: ../../0140.%20Word%20Break%20II/0140_wordBreak.h
[github-leetcode-0079]: ../../0079.%20Word%20Search/0079_exist.h
[github-leetcode-0093]: ../../0093.%20Restore%20IP%20Addresses/0093_restoreIpAddresses.h
