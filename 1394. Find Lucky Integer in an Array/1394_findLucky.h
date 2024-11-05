#pragma once
#include <vector>
using namespace std;

/*
1394. 找出数组中的幸运数
在整数数组中，如果一个整数的出现频次和它的数值大小相等，我们就称这个整数为「幸运数」。
给你一个整数数组 arr，请你从中找出并返回一个幸运数。
如果数组中存在多个幸运数，只需返回 最大 的那个。
如果数组中不含幸运数，则返回 -1 。
*/

/*
思路分析：哈希表（数组模拟）
见到频率统计，就要联想到哈希表；
见到`1 <= arr[i] <= 500`，就要联想到用数组模拟哈希表；
*/
class Solution {
public:
    int findLucky(vector<int>& arr)
    {
        int hash[501] = { 0 };
        for (int i : arr) {
            ++hash[i];
        }
        for (int i = 500; i >= 1; --i) { // 数组的下标是天然有序的，这就是用数组模拟哈希表的好处；
            if (hash[i] == i) {
                return i;
            }
        }
        return -1;
    }
};