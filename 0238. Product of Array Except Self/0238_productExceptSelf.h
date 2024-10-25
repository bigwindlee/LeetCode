#pragma once
#include <vector>
using namespace std;

/*
238. 除自身以外数组的乘积
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
*/

/*
思路分析：前缀积 + 后缀积
把nums[i]左边的数 和 右边的数 的乘积 累积起来，填入answer[i]。也就是说不包括nums[i]的其它数字的乘积。
对nums数组进行2次遍历即可。第一次正序遍历（index从0到n-1），第二次逆序遍历（index从n-1到0）；

正序遍历的目的是把nums[0]到nums[i-1]的乘积填入到answer[i]中，
逆序遍历的目的是把nums[n-1]到nums[i+1]的乘积累积到answer[i]中，这样answer[i]就包含了左右两边数字的乘积！

*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n);

        int k = 1; // k用于对nums[0]到nums[i-1]的乘积进行累积；
        for (int i = 0; i < n; ++i) {
            ans[i] = k;
            k *= nums[i];
        }

        k = 1; // 清除k值，然后用于对nums[n-1]到nums[i+1]的乘积进行累积；
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= k;
            k *= nums[i];
        }
        return ans;
    }
};