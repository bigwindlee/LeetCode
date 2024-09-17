#pragma once
#include <algorithm>
#include <numeric> // iota
#include <vector>
using namespace std;

/*
2659. 将数组清空
给你一个包含若干 互不相同 整数的数组 nums ，你需要执行以下操作 直到数组为空 ：
  ● 如果数组中第一个元素是当前数组中的 最小值 ，则删除它。
  ● 否则，将第一个元素移动到数组的 末尾 。

请你返回需要多少个操作使 nums 为空。
*/

/*
思路分析：
直观的思路，采用环形链表来模拟搬运和删除操作，时间复杂度太高(n^2)，达不到要求。

巧妙的思路，难以理解，需要仔细琢磨：
建立数组从值到索引的映射，采用按值升序排列；理想情况下，下标也是单调递增的，那么就不需要搬运操作；
如果某个数字的索引打破了“单调递增性”，那么它引发的搬运次数，只与它的相对大小有关系！（本算法的核心理念）
例如数组[3, 0, 1, 2]，值与索引结对成pair，按值升序排列：(0, 1), (1, 2), (2, 3), (3, 0)
很显然，数字3对应的索引0，打破了索引的“单调递增性”，而3是数组中“第1大”的元素，那么它引发“1”次搬运！

怎么知道一个数字是“第几大”呢？按值升序排列后，
    indexedNums[0]第n大，
    indexedNums[n-1]第一大；
    indexedNums[i] 第`n - i`大！


*/
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums)
    {
        // 记录原始数组的长度
        int n = nums.size();

        // 将原数组和索引一起存储，方便按数值大小排序
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < n; ++i) {
            indexedNums.push_back({ nums[i], i });
        }

        // 按数值对 indexedNums 进行排序
        sort(indexedNums.begin(), indexedNums.end());

        // 开始计算需要的操作次数
        long long result = n; // 至少每个元素需要一次操作来移除
        for (int i = 1; i < n; ++i) {
            // 如果一个数字的索引打破了“单调递增性”，引发的搬运次数：n - i
            // 也可以理解为从i开始，数组右边还剩下几个元素；
            // 因为i是剩下的里面最小的，还剩下几个，就是“第几大”！
            if (indexedNums[i].second < indexedNums[i - 1].second) {
                result += n - i;
            }
        }

        return result;
    }
};

/*
采用另一种方式，建立数组从值到索引的映射，并按值进行升序排列；
*/
class Solution_02 {
public:
    long long countOperationsToEmptyArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums[a] < nums[b]; }); // 索引按照对应值的大小升序排列；

        long long ans = n;
        for (int i = 1; i < n; ++i) { // 从1开始，和前面数字的索引比较，检查索引的“单调递增性”；
            if (idx[i] < idx[i - 1]) {
                ans += n - i;
            }
        }
        return ans;
    }
};
