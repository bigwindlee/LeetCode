思路：
  1）两个递归函数。第一个递归dfs()深度优先遍历当前node是否是 common ancestor；第二个递归lowertCommonAncestorHelp()深度优先遍历，判断每一个node是否是 common ancestor，如果是，则用自己刷新返回值，越往后刷新的返回值位置越低，越接近于要求的 lowest common ancestor；
