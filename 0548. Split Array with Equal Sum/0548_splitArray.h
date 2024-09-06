#pragma once
#include <unordered_set>
#include <vector>
using namespace std;

/*
548. 将数组分割成和相等的子数组
给定一个有 n 个整数的数组 nums ，如果能找到满足以下条件的三元组  (i, j, k)  则返回 true ：
1. 0 < i, i + 1 < j, j + 1 < k < n - 1
2. 子数组 (0, i - 1) ， (i + 1, j - 1) ， (j + 1, k - 1) ， (k + 1, n - 1) 的和应该相等。
这里我们定义子数组 (l, r) 表示原数组从索引为 l 的元素开始至索引为 r 的元素。

思路分析：（前缀和 + 哈希表）
找到三个分割点 (i, j, k)，把数组砍成四截，使得四个子数组的和相等（不包括分割点）。具体步骤如下：

1. 前缀和：我们可以使用前缀和数组 prefixSum 来快速计算任何子数组的和。prefixSum[i] 表示从数组起点到索引 i 的元素和。

2. 分割的条件：给定三个分割点 i, j, k，我们要求四个子数组的和相等。
    - 子数组 (0, i-1) 的和等于 prefixSum[i-1]。
    - 子数组 (i+1, j-1) 的和等于 prefixSum[j-1] - prefixSum[i]。
    - 子数组 (j+1, k-1) 的和等于 prefixSum[k-1] - prefixSum[j]。
    - 子数组 (k+1, n-1) 的和等于 prefixSum[n-1] - prefixSum[k]。

解法思路：
    固定 j，然后分别查找满足条件的 i 和 k。对于每个 j，我们需要保证：
        ● 第一段的和 等于 第二段的和；
        ● 第三段的和 等于 第四段的和；而且这个和在平分前两段时出现过。

时间复杂度：O(n^2)
外层遍历 j 的时间复杂度是 O(n)，内层遍历 i 和 k 的时间复杂度也是 O(n)，总的时间复杂度为 O(n^2)。
*/
class Solution_0548 {
public:
    bool splitArray(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 7) { // 要砍成4截，至少需要7个元素。
            return false;
        }
        // 构造前缀和数组
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // 枚举j值
        for (int j = 3; j < n - 3; ++j) {
            unordered_set<int> sums; // 四段之中，每一小段的和。
            for (int i = 1; i < j - 1; ++i) {
                if (prefixSum[i - 1] == prefixSum[j - 1] - prefixSum[i]) { // 第一段和第二段
                    sums.insert(prefixSum[i - 1]); // 只要能截断成2个和相等的子数组，就把和记录下来。
                }
            }
            for (int k = j + 2; k < n - 1; ++k) {
                if (prefixSum[k - 1] - prefixSum[j] == prefixSum[n - 1] - prefixSum[k]) { // 第三段和第四段
                    if (sums.count(prefixSum[k - 1] - prefixSum[j]) > 0) { // 这个和在平分前2段的时候出现过吗？
                        return true;
                    }
                }
            }
        }
        return false;
    }
};