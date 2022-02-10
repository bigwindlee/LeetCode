思路：
  1）典型的用递归解决树相关的问题；

  2）首先考虑把给定的函数作为递归函数，并把左右子树的结果摆出来，看看能不能用左右子树的结果和根节点构造出整棵树；
  把问题向下降解的想法不对，因为有时候问题并不直观，需要把左右子树的结果作为输入参数，经过复杂的计算才能构造出整棵树；
  所以需要首先把左右子树的结果摆出来仔细分析！

  3）如果不能，需要定义辅助的递归函数；


  func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
    if t1 == nil {
        return t2
    }    
    if t2 == nil {
        return t1
    }
    return &TreeNode{t1.Val+t2.Val, mergeTrees(t1.Left, t2.Left), mergeTrees(t1.Right, t2.Right)}
}
