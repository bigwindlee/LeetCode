<h3>思路</h3>
1）典型的回溯法；但是需要考虑一些极端的case：比如 board 矩阵为 1 x 1 的，这个时候 next move 总是非法的，因此isValid()函数的<B>位置</B>很关键，必须能让递归函数有机会返回true！

<h3>79. Word Search</h3>
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
