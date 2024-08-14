#pragma once
#include <vector>
using namespace std;

/*
287. 寻找重复数
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

思路分析：（链表环路检测/快慢指针）

数组长度 n+1，数字范围 [1, n]，没超出数组的 index，这个设计是有深意的。
把数组的 value 作为下一步的 index，可以把数组串成一个链表。
这个重复的数字，有2次机会作为index，也就是说链表在前进过程中又走到一个已经走过的节点，环路出现！

快慢指针检测环路
slow/fast同时从原点出发，slow每次一步，fast每次两步，如果存在环路，则slow/fast一定会相遇！
反证法：假设不相遇，但是存在环路fast一定会跨越slow，跨越之前是什么状态？只能是fast落后一步。
落后3步跨越不了；落后2步，再走一轮落后一步。落后一步，下次就相遇了。

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // 以上循环结束时 slow == fast，只能证明环路存在。怎么找到重复数字呢？
        // 箭头左边是index，右边是value，如果从2个不同的index跳到同一个value，那么这个value就是寻找目标。
        // slow 从原点重新出发，fast继续在环内打转，每次各走一步。两个指针在环的入口相遇，相遇点就是答案。（需要证明，见官方题解）
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        // 当他们首次相遇时（注意首次，说明上一步他们不重合），即认为他们从不同的index跳到了同一个value，这个value就是重复的。
        return slow;
    }
};