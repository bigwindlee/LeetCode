<h3>思路</h3>
<p>
1）典型的回溯法；但是有几点需要注意：
</p>
<p>
2）一刀下去，允许的长度范围是[1, 3]
</p>
<p>
3）只需切3刀，因此当 depth 为 3 时剩下的部分就是 ipaddress 的第 4 节；
</p>
<p>
4）ipaddress 的任何一节不允许前导"0"；
</p>


<h3>93. Restore IP Addresses</h3>
<a href="https://leetcode.com/problems/restore-ip-addresses/description/">here</a>
<div class="question-description">
        <p></p><p>Given a string containing only digits, restore it by returning all possible valid IP address combinations.</p>

<p>
For example:<br>
Given <code>"25525511135"</code>,
</p>
<p>
return <code>["255.255.11.135", "255.255.111.35"]</code>. (Order does not matter)
</p><p></p>
      </div>
