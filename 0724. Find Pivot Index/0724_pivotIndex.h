#pragma once
#include <vector>
using namespace std;

/*
方法一：前缀和
思路
记数组的全部元素之和为 total，当遍历到第 i 个元素时，设其左侧元素之和为 sum，则其右侧元素之和为 total - sum - nums[i]
左右侧元素和相等即为：
sum（左）+ nums[i] + sum（右）= total
也就是：
2 * sum + nums[i] = total  // 理解了这一点，就不需要把前缀和存在数组里！

当中心索引左侧或右侧没有元素时，即为零个项相加，这在数学上称作「空和」（empty sum）。在程序设计中我们约定「空和是零」。
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int total = 0, presum = 0;

        for (int num : nums) {
            total += num;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (2 * presum + nums[i] == total) {
                return i;
            }
            presum += nums[i];
        }

        return -1;
    }
};
