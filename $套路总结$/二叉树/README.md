|LeetCode|要点|
|--------------------------------|--------------------------------|
|[94. 二叉树的中序遍历][github-leetcode-0094]|二叉树常规DFS；|
|[98. 验证二叉搜索树][github-leetcode-0098]|BST中序遍历必须满足升序；|
|[101. 对称二叉树][github-leetcode-0101]|如果左树的左孩子与右树的右孩子对称，左树的右孩子与右树的左孩子对称，那么这个左树和右树就对称；|
|[102. 二叉树的层序遍历][github-leetcode-0102]|BFS算法通常需要一个队列辅助，在访问某一层的节点时，把下一层的节点加入到队列中；|
|[103. 二叉树的锯齿形层序遍历][github-leetcode-0103]|二叉树BFS；下一层入队列的顺序左右交替；|
|[106. 从中序与后序遍历序列构造二叉树][github-leetcode-0106]|postorder确定根节点，在inorder序列中查找这个根节点，把inorder分成左子树和右子树，然后递归的构建左子树和右子树！|
|[112. 路径总和][github-leetcode-0112]|在叶子节点处拦截，不要继续深入到叶子节点的null子节点；否则，到了null子节点后无法判断父节点是否叶子节点；|
|[114. 二叉树展开为链表][github-leetcode-0114]|二叉树DFS先序（根-左-右）的逆序 —— （右-左-根）|
|[116. 填充每个节点的下一个右侧节点指针][github-leetcode-0116]|二叉树BFS；下一层入队列的顺序（先右后左）；|
|[117. 填充每个节点的下一个右侧节点指针 II][github-leetcode-0117]|二叉树BFS；下一层入队列的顺序（先右后左）；|
|[124. 二叉树中的最大路径和][github-leetcode-0124]|dfs通过返回值向父节点提供收益；分开处理`最大路径能否向父节点延伸的情况`。用一个全局变量记录；|
|[173. 二叉搜索树迭代器][github-leetcode-0173]|用栈模拟二叉树中序遍历的过程；|
|[235. 二叉搜索树的最近公共祖先][github-leetcode-0235]|BST: 同一阵营则尝试下降；不同阵营则立刻返回；|
|[236. 二叉树的最近公共祖先][github-leetcode-0236]|LCA（Lowest Common Ancestor）算法；这是一个经典的递归算法；通过递归函数的返回值上浮；|
|[285. 二叉搜索树中的中序后继][github-leetcode-0285]|充分利用BST的特点进行二分查找；比给定值大的作为候选，逐步刷新；|
|[297. 二叉树的序列化与反序列化][github-leetcode-0297]|二叉树DFS；|
|[333. 最大二叉搜索子树][github-leetcode-0333]|本题演示了使用DFS遍历二叉树，在回溯时把信息逐级上报并归拢的过程。|
|[513. 找树左下角的值][github-leetcode-0513]|采用常规的先序遍历，把深度depth通过参数向下传递；记住并刷新depth递增时的第一个节点。|
|[654. 最大二叉树][github-leetcode-0654]|典型的用DFS算法递归的构建二叉树；要点是用迭代器表示数组区间；




# 二叉树专题
LeetCode 中有大量与二叉树（Binary Tree）相关的问题，这些问题涉及不同类型的二叉树（如二叉搜索树、满二叉树、平衡二叉树等）以及不同的树操作（遍历、修改、构建、删除等）。这些问题可以从简单的遍历到复杂的动态规划、回溯、分治等多种技巧。

### 一些常见的 LeetCode 二叉树相关问题：

1. **二叉树的遍历**
    * 144. **二叉树的前序遍历** (Binary Tree Preorder Traversal)
    * 94. **二叉树的中序遍历** (Binary Tree Inorder Traversal)
    * 145. **二叉树的后序遍历** (Binary Tree Postorder Traversal)
    * 102. **二叉树的层序遍历** (Binary Tree Level Order Traversal)
    * 107. **二叉树的层次遍历 II** (Binary Tree Level Order Traversal II)

2. **二叉树的构建和转换**
    * 105. **从前序和中序遍历序列构造二叉树** (Construct Binary Tree from Preorder and Inorder Traversal)
    * 106. **从中序和后序遍历序列构造二叉树** (Construct Binary Tree from Inorder and Postorder Traversal)
    * 108. **将有序数组转换为二叉搜索树** (Convert Sorted Array to Binary Search Tree)

3. **二叉树的最大深度和最小深度**
    * 104. **二叉树的最大深度** (Maximum Depth of Binary Tree)
    * 111. **二叉树的最小深度** (Minimum Depth of Binary Tree)

4. **二叉树的路径问题**
    * 112. **路径总和** (Path Sum)
    * 113. **路径总和 II** (Path Sum II)
    * 124. **二叉树中的最大路径和** (Binary Tree Maximum Path Sum)

5. **二叉搜索树相关问题**
    * 98. **验证二叉搜索树** (Validate Binary Search Tree)
    * 230. **二叉搜索树中第K小的元素** (Kth Smallest Element in a BST)
    * 235. **二叉搜索树的最近公共祖先** (Lowest Common Ancestor of a Binary Search Tree)

6. **树的形态检查**
    * 101. **对称二叉树** (Symmetric Tree)
    * 100. **相同的树** (Same Tree)
    * 110. **平衡二叉树** (Balanced Binary Tree)

7. **二叉树的修改**
    * 116. **填充每个节点的下一个右侧节点指针** (Populating Next Right Pointers in Each Node)
    * 117. **填充每个节点的下一个右侧节点指针 II** (Populating Next Right Pointers in Each Node II)
    * 226. **翻转二叉树** (Invert Binary Tree)

8. **二叉树的序列化和反序列化**
    * 297. **二叉树的序列化与反序列化** (Serialize and Deserialize Binary Tree)

---

### 解决二叉树问题的核心思想

解决二叉树问题的核心思想可以概括为以下几个方面：

#### 1. **遍历二叉树**
* **前序遍历 (Preorder Traversal)**: 访问根节点，然后遍历左子树，最后遍历右子树。常用于问题中的树的构建或遍历问题。
* **中序遍历 (Inorder Traversal)**: 遍历左子树，访问根节点，最后遍历右子树。常用于处理 **二叉搜索树 (BST)** 相关问题。
* **后序遍历 (Postorder Traversal)**: 遍历左子树，遍历右子树，最后访问根节点。常用于处理需要从底部到顶部计算值的问题，如计算树的深度、删除节点等。
* **层序遍历 (Level Order Traversal)**: 使用队列按层遍历，逐层处理二叉树的节点，常用于宽度优先搜索。

#### 2. **递归与分治**
* **递归 (Recursion)**: 由于树的结构天然具有递归特性，许多树问题可以通过递归来解决。例如，遍历、路径和、树的深度、判断对称等问题都可以通过递归来实现。
* **分治 (Divide and Conquer)**: 树结构可以视作多个子树的组合，因此在处理树问题时可以将问题划分为对左右子树分别求解，再将结果合并。

#### 3. **动态规划**
* 在一些复杂的树问题中，可以使用动态规划来优化计算。例如，在求解二叉树中的最大路径和时，可以用动态规划的思想记录当前节点的最优解，然后通过回溯更新全局的最大值。

#### 4. **迭代法**
* 虽然递归是树问题的常用解法，但递归可能导致栈溢出。迭代法使用显式的栈来模拟递归过程，可以避免这个问题。例如，利用栈来实现树的前序、中序、后序遍历，或利用队列实现层序遍历。

#### 5. **二叉搜索树性质**
* **二叉搜索树 (BST)** 有一个重要的性质：左子树的所有节点值都小于根节点，右子树的所有节点值都大于根节点。这个性质可以用于搜索、验证、找最小值/最大值等问题。

#### 6. **深度优先搜索（DFS）与广度优先搜索（BFS）**
* **DFS (Depth First Search)**: 使用递归或栈实现，深入到树的最深处再逐步回溯。
* **BFS (Breadth First Search)**: 使用队列逐层遍历节点，常用于找到最短路径、最小深度等问题。

#### 7. **父子节点的关系处理**
* 在解决一些树问题时（如查找最近公共祖先），需要追踪父节点或通过递归传递一些额外的信息。通过额外的参数或数据结构来保存节点和父节点的关系，是解决这类问题的一种常用技巧。


[github-leetcode-0094]: ../../0094.%20Binary%20Tree%20Inorder%20Traversal/0094_inorderTraversal.h
[github-leetcode-0098]: ../../0098.%20Validate%20Binary%20Search%20Tree/0098_isValidBST.h
[github-leetcode-0101]: ../../0101.%20Symmetric%20Tree/0101_isSymmetric.h
[github-leetcode-0106]: ../../0106.%20Construct%20Binary%20Tree/0106_buildTree.h
[github-leetcode-0333]: ../../0333.%20Largest%20BST%20Subtree/0333_largestBSTSubtree.h
[github-leetcode-0654]: ../../0654.%20Maximum%20Binary%20Tree/0654_constructMaximumBinaryTree.h
[github-leetcode-0513]: ../../0513.%20Find%20Bottom%20Left%20Tree%20Value/0513_findBottomLeftValue.h
[github-leetcode-0102]: ../../0102.%20Binary%20Tree%20Level%20Order%20Traversal/0102_levelOrder.h
[github-leetcode-0112]: ../../0112.%20Path%20Sum/0112_hasPathSum.h
[github-leetcode-0124]: ../../0124.%20Binary%20Tree%20Maximum%20Path%20Sum/0124_maxPathSum.h
[github-leetcode-0285]: ../../0285.%20Inorder%20Successor%20in%20BST/0285_inorderSuccessor.h
[github-leetcode-0235]: ../../0235.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Search%20Tree/0235_lowestCommonAncestor.h
[github-leetcode-0236]: ../../0236.%20LCA%20of%20a%20Binary%20Tree/0236_lowestCommonAncestor.h
[github-leetcode-0297]: ../../0297.%20Serialize%20and%20Deserialize%20Binary%20Tree/0297_serialize.h
[github-leetcode-0114]: ../../0114.%20Flatten%20Binary%20Tree%20to%20Linked%20List/0114_flatten.h
[github-leetcode-0116]: ../../0116.%20Populating%20Next%20Right%20Pointers/0116_connect.h
[github-leetcode-0117]: ../../0117.%20Populating%20Next%20Right%20Pointers%20II/0117_connect.h
[github-leetcode-0103]: ../../0103.%20Binary%20Tree%20Zigzag%20Level%20Order%20Traversal/0103_zigzagLevelOrder.h
[github-leetcode-0173]: ../../0173.%20Binary%20Search%20Tree%20Iterator/0173_BSTIterator.h
