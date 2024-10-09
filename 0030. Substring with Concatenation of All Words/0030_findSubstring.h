#pragma once
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
30. 串联所有单词的子串
给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。
*/

/*
思路分析：滑动窗口 + 哈希表
i指针的范围是[0, wordLen)，要避免重复的统计，否则会超时；
以i指针为起点，subLen为窗口长度，每次向右滑动wordLen，右边新加入一个word，左边退出一个word，以此更新哈希表differ；
哈希表differ的设计很巧妙；
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> ans; // 存储结果的数组
        int wordCount = words.size(), wordLen = words[0].size(); // 单词数量、单词长度
        int subLen = wordCount * wordLen;
        int lastIdx = s.size() - subLen;

        // 外层循环，从每个可能的起始位置 i 开始，注意 i 的范围
        for (int i = 0; i < wordLen && i <= lastIdx; ++i) {
            unordered_map<string, int> differ; // 用于统计当前窗口内单词的出现次数
            // 统计从当前起始位置 i 开始的 wordCount 个单词
            for (int j = 0; j < wordCount; ++j) {
                ++differ[s.substr(i + j * wordLen, wordLen)]; // 将子串加入到 differ 中并计数
            }
            // 遍历 words 中的每个单词，检查其在 differ 中的出现次数
            for (string& word : words) {
                if (--differ[word] == 0) { // 如果单词的计数减为 0，则从 differ 中删除
                    differ.erase(word);
                }
            }
            // 内层循环，从起始位置 i 开始滑动窗口，每次滑动一个word长度
            for (int start = i; start <= lastIdx; start += wordLen) {
                if (start != i) {
                    // 添加新进入窗口的单词到 differ 中
                    string word = s.substr(start + subLen - wordLen, wordLen); //窗口右边加的单词
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }
                    // 移除窗口左侧移出的单词
                    word = s.substr(start - wordLen, wordLen);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                // 如果 differ 为空，表示当前窗口符合要求，将起始位置加入结果数组 ans
                if (differ.empty()) {
                    ans.emplace_back(start);
                }
            }
        }
        return ans;
    }
};