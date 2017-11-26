<h3>思路</h3>
<p>
1）所有bit位从全0开始，每次只允许变化1个bit；给定bit位数n，打印出 gray code 序列；
</p>
<p>
2）不算典型的回溯法，但可借鉴回溯法的解法；
</p>


<h3>89. Gray Code</h3>
<a href="https://leetcode.com/problems/gray-code/description/">here</a>
<div class="question-description">
        <p></p><p>The gray code is a binary numeral system where two successive values differ in only one bit.</p>

<p>Given a non-negative integer <i>n</i> representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.</p>

<p>For example, given <i>n</i> = 2, return <code>[0,1,3,2]</code>. Its gray code sequence is:</p>
<pre>00 - 0
01 - 1
11 - 3
10 - 2
</pre>

<p><b>Note:</b><br>
For a given <i>n</i>, a gray code sequence is not uniquely defined.
</p>
<p>For example, <code>[0,2,3,1]</code> is also a valid gray code sequence according to the above definition.</p>

<p>For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.</p><p></p>
</div>
