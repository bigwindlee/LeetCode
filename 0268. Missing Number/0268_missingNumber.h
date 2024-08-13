#pragma once
#include <vector>
using namespace std;

/*
268. 丢失的数字
给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

思路分析1：
计数的问题，都可以考虑哈希表（或者哈希表的变体 -- 数组）；
[0, n]的闭区间一共有 n+1 个数，但是缺失了一个数，一共有 n 个，也就是nums的长度为n；
另准备一个长度为 n+1 的数组arr，使用nums中的数字作为arr的下标，进行标记，那么一定有一个下标没有被标记！
没被标记的下标就是丢失的数字！

思路分析2：
其实这是一道简单的数学题。把闭区间[0, n]中所有的数字加起来，然后依次减去nums中的数字，就会把缺失的数字暴露出来！
思路2改进版：考虑到溢出风险，改成“边加边减”！

思路分析3：
见到“去除重复数字”，就要联想到“异或”操作！
*/

class Solution_0268_03 { // 思路3：位运算（异或）
public:
    int missingNumber(vector<int>& nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i <= n; ++i) {
            ans ^= i;
        }
        for (int i : nums) {
            ans ^= i;
        }
        return ans;
    }

    // 异或改进版：异或操作，一次循环。
    int missingNumber_plus(vector<int>& nums)
    {
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans ^= (i ^ nums[i]);
        }
        return ans;
    }
};

class Solution_0268_02 { // 思路2：数学方法
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        // 把闭区间[0, n]中所有的数字加起来
        int sum = n * (n + 1) / 2;
        // 依次减去nums中的数字
        for (int i : nums) {
            sum -= i;
        }
        return sum;
    }

    // 思路2改进版：考虑到溢出风险，改成“边加边减”！
    int missingNumber_plus(vector<int>& nums)
    {
        int n = nums.size();
        int ans = n; // 下标i的分布是[0, n-1]，所以提前把n加进来。
        for (int i = 0; i < n; ++i) {
            ans += i - nums[i];
        }
        return ans;
    }
};

class Solution_0268_01 { // 思路1：哈希计数
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> arr(n + 1); // 标记数组（哈希表变体）
        for (int i : nums) {
            arr[i] = 1; // 标记
        }
        // 遍历寻找未被标记的下标
        for (int i = 0; i <= n; ++i) {
            if (arr[i] == 0) { // 未被标记
                return i;
            }
        }
        return -1;
    }
};