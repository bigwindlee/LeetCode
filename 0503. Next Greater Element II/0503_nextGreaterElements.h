#pragma once
#include <stack>
#include <vector>
using namespace std;

/*

思路分析1：（暴力枚举）
枚举每个nums[i]，往后找第一个大于nums[i]的数，最多搜索n-1次（不包括自己）。

思路分析2：（单调栈）
“下一个/前一个更大或更小的元素”这类问题，是单调栈的经典应用。
维持一个单调递减栈，枚举nums[i]并加入递减栈。如果当前nums[i]比栈顶元素大，那么说明栈顶元素遇到了首个比它大的值！（本题核心）
循环的踢掉栈顶，被踢掉的元素也正好找到了解。
入栈的是数组元素的下标！

怎样解决循环数组问题？
    可以把 nums 复制一份，拼在 nums 右边。但代码实现时，无需真的把数组复制一份，只需扩大循环范围，并用下标模 n 的方式取到对应的元素值。
*/

class Solution_0503_02 {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1); // 初值为-1，首先假定没找到。
        stack<int> stk;

        // 本题 nums 是一个循环数组，nums[n−1] 右边是 nums[0]。我们可以把 nums 复制一份，拼在 nums 右边，这样就把环形数组变成一般数组了。
        // 代码实现时，无需真的把数组复制一份，而是用下标模 n 的方式取到对应的元素值。
        for (int i = 0; i < n * 2; ++i) {
            int x = nums[i % n];
            while (!stk.empty() && x > nums[stk.top()]) { // 循环踢掉栈顶元素，如果比它大的话。
                ans[stk.top()] = x; // 能够踢掉栈顶元素的，一定是首个比它大的值；
                stk.pop();
            }
            if (i < n) {
                stk.push(i); // 踢完了栈顶元素，就该自己（下标）入栈了。（入栈下标对应的值递减）
            }
        }
        return ans;
    }
};

// 思路1：暴力破解，效率低。
class Solution_0503_01 {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1); // 首先假设没找到
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                int k = (i + j) % n;
                if (nums[k] > nums[i]) {
                    ans[i] = nums[k]; // 找到了，覆盖它。
                    break;
                }
            }
        }
        return ans;
    }
};
