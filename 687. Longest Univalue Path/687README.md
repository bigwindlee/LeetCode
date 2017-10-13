Longest-Univalue-Path of a tree is among those Longest-Univalue-Path-Across at each node;
Longest-Univalue-Path-Across a node is sum of { Longest-Univalue-Path-Start-At each child with same value, + 1}

Java

class Solution {
    public int longestUnivaluePath(TreeNode root) {
        int[] res = new int[1];
        if (root != null) dfs(root, res);
        return res[0];
    }

    private int dfs(TreeNode node, int[] res) {
        int l = node.left != null ? dfs(node.left, res) : 0;
        int r = node.right != null ? dfs(node.right, res) : 0;
        int resl = node.left != null && node.left.val == node.val ? l + 1 : 0;
        int resr = node.right != null && node.right.val == node.val ? r + 1 : 0;
        res[0] = Math.max(res[0], resl + resr);
        return Math.max(resl, resr);
    }
}
C++

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int lup = 0;
        if (root) dfs(root, lup);
        return lup;
    }

private:
    int dfs(TreeNode* node, int& lup) {
        int l = node->left ? dfs(node->left, lup) : 0;
        int r = node->right ? dfs(node->right, lup) : 0;
        int resl = node->left && node->left->val == node->val ? l + 1 : 0;
        int resr = node->right && node->right->val == node->val ? r + 1 : 0;
        lup = max(lup, resl + resr);
        return max(resl, resr);
    }
};
Varables
l is the length of single direction Longest-Univalue-Path start from left-child,
r is the length of single direction Longest-Univalue-Path start from right-child,
resl is the length of single direction Longest-Univalue-Path start from parent go left,
resr is the length of single direction Longest-Univalue-Path start from parent go right.
int dfs(node) returns the Longest-Univalue-Path-Start-At that node, and update the result of Longest-Univalue-Path-Across that node through side effect.
It is really hard to name those variables to reflect these concept.

Example:

                ...
               /   
              4 (res = resl + resr = 3)
  (resl = 2) / \ (resr= 1)
    (l = 1) 4   4 (r = 0)
           /     
          4
resl is Longest-Univalue-Path-Start-At left node + 1,
resr is Longest-Univalue-Path-Start-At right node + 1,
in here the local result of Longest-Univalue-Path-Across at this node is the sum of the 2;
