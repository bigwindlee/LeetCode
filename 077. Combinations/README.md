<B>思路</B>

  1）典型的回溯法；回溯法的本质是二维展开；回溯法的核心和确定2个维度分别是什么，以及isValid()函数的设计；

  2）本题的要点在于isValid()函数的设计：if len(path) == 0 || i > path[len(path)-1]

<B>077. Combinations</B>
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
