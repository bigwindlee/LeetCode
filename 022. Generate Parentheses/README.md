<B>思路：</B>

  1）回溯法的本质是二维展开，回溯法的核心的确定2个维度分别是什么。

  2）就本题而言，第一个维度是在'('和')'之间的变化，因此可用for循环遍历[]bool{true, false}来表示，true对应'('，false对应')'；

  3）第2个维度就是depth，也就是 n pairs of parentheses 的长度(2n)；




---------------------------------------------------------------------------------------------------------------------
<B>22. Generate Parentheses</B>

  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

  For example, given n = 3, a solution set is:

  [
    "((()))",
    "(()())",
    "(())()",
    "()(())",
    "()()()"
  ]
