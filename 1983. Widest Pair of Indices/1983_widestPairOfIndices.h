#pragma once
#include <unordered_map>
#include <vector>
using namespace std;

/*
1983. 范围和相等的最宽索引对
给定两个 以0为索引 的二进制数组 nums1 和 nums2 。找出 最宽 的索引对 (i, j) ，使的 i <= j 并且 nums1[i] + nums1[i+1] + ... + nums1[j] == nums2[i] + nums2[i+1] + ... + nums2[j]。
最宽 的指标对是指在 i 和 j 之间的 距离最大 的指标对。一对指标之间的 距离 定义为 j - i + 1 。
返回 最宽 索引对的 距离 。如果没有满足条件的索引对，则返回 0 。
*/

/*
思路分析：差值的累加和
有前缀和的思想，但并不是普通的前缀和解法；核心思想是累加2个数组对应位置的差值，并记入哈希表。
如果差值累加和再次出现，意味着从上次出现的之后的位置到当前的i，这一段区间没有产生差值，也就是2个数组在这段区间的和相等！

特殊情况处理：
如果差值累加和为0，则当前走过的整个区间都符合条件，这是理论上最长的区间，无需比较。
*/
class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2)
    {
        int sum = 0, ans = 0, n = nums1.size();
        unordered_map<int, int> hash; // 差值累加和 => 数组下标
        for (int i = 0; i < n; ++i) {
            sum += nums1[i] - nums2[i];
            if (sum == 0) {
                ans = i + 1; // 理论上最大的跨度，无需比较；
            } else if (hash.count(sum) > 0) { // 核心：sum再次出现，意味着从上次出现之后的位置到当前的i，两个数组在这段区间的和相等。
                ans = max(ans, i - hash[sum]); // 候选跨度
            } else {
                hash[sum] = i; // 首次出现的sum，记住哈希表；
            }
        }
        return ans;
    }
};