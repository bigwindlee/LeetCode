<h3>思路</h3>
1）典型的回溯法；但是需要考虑一些极端的case：比如 board 矩阵为 1 x 1 的，这个时候 next move 总是非法的，因此isValid()函数的<B>位置</B>很关键，必须能让递归函数有机会返回true！
2）isValid()函数只判断本次递归参数的有效性，不要试图去判断下次递归调用的参数的有效性，让它自己去判断！否则会无法返回true！
  <B>if isValid(board, row, col) && !visit[row][col] && board[row][col] == word[depth]</B>

<h3>79. Word Search</h3>
<div class="question-description">
 <p></p>
 <p> Given a 2D board and a word, find if the word exists in the grid. </p>
 <p> The word can be constructed from letters of sequentially adjacent cell, where &quot;adjacent&quot; cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once. </p>
 <p> For example,<br /> Given <b>board</b> = </p>
 <pre>[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
</pre>
 <b>word</b> =
 <code>&quot;ABCCED&quot;</code>, -&gt; returns
 <code>true</code>,
 <br />
 <b>word</b> =
 <code>&quot;SEE&quot;</code>, -&gt; returns
 <code>true</code>,
 <br />
 <b>word</b> =
 <code>&quot;ABCB&quot;</code>, -&gt; returns
 <code>false</code>.
 <br />
 <p></p>
 <p></p>
</div>
