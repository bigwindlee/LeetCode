#pragma once
#include <vector>
using namespace std;

/*
16. 最接近的三数之和
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
返回这三个数的和。
假定每组输入只存在恰好一个解。

思路分析：（排序 + 三指针）
从数组中选出3个元素，思路都一样，先排序，再三指针扫描。
使用指针 i 对数组进行扫描；在扫描的过程中，对 i 右侧的区间，使用 left/right 指针进行夹逼，寻找更符合条件的解。

优化点：三个指针都要去重。
*/
class Solution_0016 {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int ans, sum;
        sort(nums.begin(), nums.end()); // 排序便于优化
        size_t n = nums.size();
        int offset = INT_MAX, new_offset;
        for (size_t i = 0; i <= n - 3; ++i) { // i最多到n-3，因为要留2个位置给left/right。
            // 优化：i 指针去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 优化：i 所在的最小的三个数的和，如果都比target大，那么其它组合，以及 i 之后的组合，都会更大！
            sum = nums[i] + nums[i + 1] + nums[i + 2];
            if (sum > target) {
                new_offset = sum - target;
                if (new_offset < offset) {
                    // 跳出for循环，所以此处无需刷新offset。
                    ans = sum;
                }
                break; // i 及 i 之后的组合只会更大，离target更远！
            }
            // 优化：i 所在的最大的三数之和，都比target小，其它组合只会更小。
            sum = nums[i] + nums[n - 2] + nums[n - 1];
            if (sum < target) {
                new_offset = target - sum;
                if (new_offset < offset) {
                    offset = new_offset;
                    ans = sum;
                }
                continue; // i 所在的其它组合只会更小，离target更远！
            }
            // i的右侧区间使用2个指针进行夹逼
            // left只能往右，right只能往左。
            size_t left = i + 1, right = n - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum > target) {
                    new_offset = sum - target;
                    if (new_offset < offset) {
                        offset = new_offset;
                        ans = sum;
                    }
                    // sum太大，想要变小一点；right指针左移并去重
                    for (--right; left < right && nums[right] == nums[right + 1]; --right)
                        ;
                } else if (sum < target) {
                    new_offset = target - sum;
                    if (new_offset < offset) {
                        offset = new_offset;
                        ans = sum;
                    }
                    // sum太小，想要变大一点；left指针右移并去重
                    for (++left; left < right && nums[left] == nums[left - 1]; ++left)
                        ;
                } else {
                    return sum;
                }
            }
        }
        return ans;
    }
};