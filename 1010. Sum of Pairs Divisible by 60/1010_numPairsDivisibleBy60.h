#pragma once
#include <unordered_set>
#include <vector>
using namespace std;

/*
1010. 总持续时间可被 60 整除的歌曲
在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。
返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望下标数字 i 和 j 满足  i < j 且有 (time[i] + time[j]) % 60 == 0。

思路分析：（哈希表）
要在数组中寻找符合条件的元素对，可借鉴第一题“1. 两数之和”的思路，直接询问哈希表，队友是否存在。
用哈希表统计余数出现的频率。

难点：
元素成对的条件是，相加可被60整除。那么这2个数对60取余，余数之和为0，或者60.
因为60的倍数太多了，要利用“余数”做文章，是本题的技巧所在。
枚举数组time中的数字，对60取余，那么“队友”的余数应该是(60-mod)，考虑到mod为0的情况，“队友”的余数应为：(60-mod)%60
*/
class Solution_1010 {
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        int ans = 0;
        unordered_map<int, int> mods; // key值范围[0, 59]，可特化成数组：`int mods[60]{};`
        for (int i : time) {
            int mod = i % 60;
            ans += mods[(60 - mod) % 60]; // 统一处理mod为0的情况。
            ++mods[mod];
        }
        return ans;
    }
};