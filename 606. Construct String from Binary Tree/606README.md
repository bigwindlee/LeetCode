总结：
  1）本题是典型的利用递归解决树相关的问题，先把左右子树的结果摆出来，然后利用根节点和左右子树的结果协作生成整棵树。

  2）关键点在于当左子树为空时，是否应该打印出空括号？这取决于右子树是否存在；如果左子树为空而右子树不为空，就应该打印出左子树的空括号。
