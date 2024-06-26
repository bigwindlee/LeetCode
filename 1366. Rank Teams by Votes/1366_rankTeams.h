#pragma once
#include <string>
#include <vector>
using namespace std;

/* 
主要步骤如下：
1）初始化一个 unordered_map 来存储每个队伍在每个位置的票数。
2）遍历 votes 数组，统计每个队伍在每个位置上的票数。
3）将统计结果存储到一个 vector 中以便排序。
4）使用自定义的排序规则对队伍进行排序：首先根据票数进行排序，如果票数相同，则按字母顺序排序。
5）根据排序结果生成最终的排名字符串。

重要的是设计出一个统计每支队伍在各个位置的得票数的数据结构：
    unordered_map<char, vector<int>> rankMap;
统计票数的巧妙之处：
    rankMap[vote[i]][i]++

知识点：
1）设计统计票数的数据结构；
2）统计票数；
3）无序哈希表展开成vector，便于排序；
4）使用lambda表达式实现排序规则；
5）利用lambda表达式对vector进行排序；
*/
class Solution_1366 {
public:
    string rankTeams(vector<string>& votes)
    {
        int n = votes[0].size();
        unordered_map<char, vector<int>> rankMap; // 统计票数的数据结构

        // Initialize the rank map
        for (char c : votes[0]) {
            rankMap[c] = vector<int>(n, 0);
        }

        // Count the votes
        for (const string& vote : votes) {
            for (int i = 0; i < n; ++i) {
                rankMap[vote[i]][i]++; // 巧妙的统计票数
            }
        }

        // Convert the rank map to a vector of pairs for sorting
        // 键和值结成一对(pair)放在vector中，目的是为了根据票数排序。
        vector<pair<char, vector<int>>> rankVec(rankMap.begin(), rankMap.end());

        // Custom sort comparator
        // 设计一个lambda表达式，实现排序规则：依次按照被排在第一位的得票数、被排在第二位的得票数，以此类推。
        auto comparator = [](const pair<char, vector<int>>& a, const pair<char, vector<int>>& b) {
            for (int i = 0; i < a.second.size(); ++i) {
                if (a.second[i] != b.second[i]) {
                    return a.second[i] > b.second[i];
                }
            }
            return a.first < b.first; // 如果最后还是并列，则根据字母顺序。
        };

        // 根据排序规则进行排序
        sort(rankVec.begin(), rankVec.end(), comparator);

        // Generate the result string
        string ans;
        for (const auto& p : rankVec) {
            ans += p.first;
        }

        return ans;
    }
};