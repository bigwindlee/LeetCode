<h3>思路</h3>
<p>
1）本题的解法非常巧妙。要让2个指针在 intersection 出汇集，那么它们之前走过的距离应该一样长。怎么才能使走过的距离一样长呢？
</p>
<p>
2）一个指针从 headA 开始，走到头则切换到 headB；一个指针从 headB 开始，走到头则切换到 headA；
</p>
<p>
3）如果2个链表有交点，那么2个指针会汇集在交点；如果2个链表没有交点，那么经过一次切换后2个指针双双达到链表尾部NULL；（体会一下之前走过的距离）
</p>

<h3>160. Intersection of Two Linked Lists</h3>
<a href="https://leetcode.com/problems/intersection-of-two-linked-lists/description/">here</a>
<div class="question-description">
        <p></p><p>Write a program to find the node at which the intersection of two singly linked lists begins.</p>
<br>
<p>For example, the following two linked lists: </p>
<pre>
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
</pre>
<p>begin to intersect at node c1.</p>
<br>
<p><b>Notes:</b>
</p><ul>
<li>If the two linked lists have no intersection at all, return <code>null</code>.</li>
<li>The linked lists must retain their original structure after the function returns. </li>
<li>You may assume there are no cycles anywhere in the entire linked structure.</li>
<li>Your code should preferably run in O(n) time and use only O(1) memory.</li>
</ul>
<p></p>
</div>
