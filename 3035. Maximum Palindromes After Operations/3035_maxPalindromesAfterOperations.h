#pragma once
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
3035. 回文字符串的最大数量 （哈希统计 + 贪心）
给你一个下标从 0 开始的字符串数组 words ，数组的长度为 n ，且包含下标从 0 开始的若干字符串。
你可以执行以下操作 任意 次数（包括零次）：
选择整数i、j、x和y，满足0 <= i, j < n，0 <= x < words[i].length，0 <= y < words[j].length，交换 字符 words[i][x] 和 words[j][y] 。
返回一个整数，表示在执行一些操作后，words 中可以包含的回文串的 最大 数量。
注意：在操作过程中，i 和 j 可以相等。

思路分析：
字符矩阵中的任意字符都可以无限次交换，所表达的意思，就是把所有字符收集到一起，在回填到字符串中，尽可能形成最多的回文串。
贪心：
    回填字符的时候，要优先回填更短的字符串，这样能消耗更少的成对字符pair，形成最多的回文串。
注意：
    长度为len的字符串，回填的时候需要消耗 len/2 个字符pair才能构成回文串；len为奇数，或者len为1，都成立！无需单独处理特例！
    从这个角度考虑问题，是本题的关键！
*/
class Solution_3035 {
public:
    int maxPalindromesAfterOperations(vector<string>& words)
    {
        // 频率统计一般使用哈希表unordered_map；但是本题全部都是小写字符，把它特化成一个长度26的int数组即可。
        // 从a到z对应数组下标0~25；注意转换的技巧：char - 'a'
        vector<int> freq(26);
        // 记录每个字符串的长度，一会儿还要根据长度排序；
        vector<int> lens;
        for (const string& word : words) {
            for (char c : word) {
                ++freq[c - 'a'];
            }
            lens.push_back(word.size());
        }
        int pairs = 0;
        for (int f : freq) {
            pairs += f / 2; // 能够组成一对的字符pairs数量
        }
        // 默认升序，因为我们要优先回填长度更短的字符串；
        sort(lens.begin(), lens.end());
        int ans = 0;
        for (int len : lens) {
            pairs -= len / 2; // 消耗掉的字符pairs
            if (pairs < 0)
                break;
            ++ans;
        }
        return ans;
    }
};