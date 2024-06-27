#pragma once
#include <unordered_map>
#include <vector>
using namespace std;

/*
前缀和 + 哈希表

但凡见到“连续子数组”，就要联想到`前缀和`；前缀和（Prefix Sum）是一种用于高效处理数组区间和的技术；
前缀和数组 P 的每个元素 P[i] 表示原数组 A 从起始位置A[0]到第 i 个元素的累计和：P[i] = A[0] + A[1] + ... + A[i]
通过前缀和数组，可以在常数时间内（O(1)）计算任意子数组 A[l] 到 A[r] 的和：P[r] - p[l-1]
当l为0时，定义p[-1]=0，本质上是增加了一个dummyHead，便于统一的计算子数组长度；
这也是下面的哈希表中：sumIndexMap[0] = -1 的原因。

详细解法
1）将数组中的 0 看作 -1，这样我们可以将问题转换为找到和为 0 的最长连续子数组。
2）使用一个哈希表来记录每个前缀和第一次出现的下标。
3）遍历数组，计算前缀和：
    - 如果当前前缀和已经在哈希表中出现过，则说明从哈希表记录的下标到当前下标之间的子数组的和为 0。此时计算该子数组的长度并更新最大长度。
    - 如果当前前缀和没有在哈希表中出现过，则将当前前缀和及其下标记录到哈希表中。

找最大值、最小值、最接近的值，常见的思路是，用所有可能的解不停刷新。
*/
class Solution_0525 {
public:
    int findMaxLength(vector<int>& nums)
    {
        int ans = 0; // 最大长度
        int sum = 0; // 前缀和
        unordered_map<int, int> sumIndexMap;
        sumIndexMap[0] = -1; // 计算子数组长度必须有一个起点，将index=-1作为起点，类似于链表的dummyHead。例如{0, 1}这种case；

        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 1) ? 1 : -1;
            if (sumIndexMap.find(sum) == sumIndexMap.end()) {
                sumIndexMap[sum] = i;
            } else {
                // 本题精髓：如果当前`前缀和`已经在哈希表中出现过，则说明从哈希表记录的下标到当前下标之间的子数组的和为 0。
                ans = max(ans, i - sumIndexMap[sum]); // 用所有可能的解不停刷新
            }
        }

        return ans;
    }
};