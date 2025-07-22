#pragma once
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

class Solution_0645 {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        // 把nums和[1~n]从概念上合并成一个大数组；把大数组中所有元素异或到sum；
        int sum = accumulate(nums.begin(), nums.end(), 0, std::bit_xor<>());
        for (int i = 1; i <= nums.size(); ++i) {
            sum ^= i;
        }

        // 提取异或结果的lowbit，根据lowbit把大数组分成2组；
        // 令x为重复的数字，y为缺失的数字；那么分成的2组必然是：
        // 3个x领衔的一组（以及其它成对出现的元素）；1个y领衔的另外一组（以及其它成对出现的元素）；
        // 因为x和y的出现次数是奇数次，对这2组分别执行异或，可使x和y暴露出来；
        int lowbit = sum & -sum, a = 0, b = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            if (i & lowbit) {
                a ^= i;
            } else {
                b ^= i;
            }
        }
        for (int n : nums) {
            if (n & lowbit) {
                a ^= n;
            } else {
                b ^= n;
            }
        }

        // 此时a/b哪个是重复的数字，哪个是缺失的数字，还不知道；
        // 如果能在nums数组中找到，就是重复的；
        if (find(nums.begin(), nums.end(), a) == nums.end()) {
            return { b, a }; // 没找到a，说明a是缺失的；
        }
        return { a, b };
    }
};