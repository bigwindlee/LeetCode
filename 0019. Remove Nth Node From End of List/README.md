<h3>思路</h3>
<p>
1）链表的变化包括指针的速度（龟兔算法），指针的路径等；
</p>
<p>
2）本题使用slow/fast指针（龟兔算法），fast指针到头时，slow指针指向待删的node；
</p>
<p>
3）头节点也可能是待删节点，因此为避免头节点的特殊处理，一般使用dummyHead；
</p>

<h3>19. Remove Nth Node From End of List</h3>
<a href="https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/">here</a>
<div class="question-description">
        <p></p><p>Given a linked list, remove the <i>n</i><sup>th</sup> node from the end of list and return its head.</p>

<p>
For example,</p>

<pre>   Given linked list: <b>1-&gt;2-&gt;3-&gt;4-&gt;5</b>, and <b><i>n</i> = 2</b>.

   After removing the second node from the end, the linked list becomes <b>1-&gt;2-&gt;3-&gt;5</b>.
</pre>

<p>
<b>Note:</b><br>
Given <i>n</i> will always be valid.<br>
Try to do this in one pass.
</p><p></p>
</div>
