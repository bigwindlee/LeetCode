思路：
  1）利用递归函数的返回值记录和传递结果。

  2）在本例中递归函数的返回值为 diameter and height；
  在dfs遍历树时记录出现过的最大的diameter；
  记住子树的height，利用它来计算 parent tree 的 height，这是一种常见的手法，可避免重头计算每个节点的height！
