#pragma once
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

/*
* 403. 青蛙过河
一只青蛙想要过河。 假定河流被等分为若干个单元格，并且在每一个单元格内都有可能放有一块石子（也有可能没有）。 青蛙可以跳上石子，但是不可以跳入水中。
给你石子的位置列表 stones（用单元格序号 升序 表示）， 请判定青蛙能否成功过河（即能否在最后一步跳至最后一块石子上）。开始时， 青蛙默认已站在第一块石子上，并可以假定它第一步只能跳跃 1 个单位（即只能从单元格 1 跳至单元格 2 ）。
如果青蛙上一步跳跃了 k 个单位，那么它接下来的跳跃距离只能选择为 k - 1、k 或 k + 1 个单位。 另请注意，青蛙只能向前方（终点的方向）跳跃。
*/

/*
思路分析：动规
1. 初始检查：首先检查青蛙能否从第一块石子跳到第二块（因为第一步必须跳 1 个单位）。
2. 哈希表 stone_map：用来记录每个石头位置能跳的步数。初始时，青蛙站在第一个石头（位置 0）上，只能跳 1 个单位。
3. 遍历每个石头：对于每块石头，如果能跳到某个石头，则更新下一块石头上能跳的步数（k-1, k, k+1）。
4. 成功条件：如果某次跳跃正好能跳到最后一块石头的位置，返回 true。
5. 终止条件：遍历完所有石头后，如果没有找到可以跳到最后的路径，则返回 false。
*/
class Solution {
public:
    bool canCross(vector<int>& stones)
    {
        if (stones[1] != 1) return false; // 第一跳必须是 1

        // 使用 unordered_map 记录每个石头的位置能跳的步数集合
        unordered_map<int, unordered_set<int>> stone_map;
        for (int stone : stones) {
            stone_map[stone] = unordered_set<int>();
        }
        stone_map[0].insert(1); // 起点只能跳 1

        for (int i = 0; i < stones.size(); i++) {
            int stone = stones[i];
            for (int jump : stone_map[stone]) {
                int next_pos = stone + jump;
                if (next_pos == stones.back()) {
                    return true; // 成功跳到最后一个石头
                }
                // 如果可以跳到某个石头，更新这个石头上能跳的步数
                if (stone_map.count(next_pos) > 0) {
                    if (jump - 1 > 0) stone_map[next_pos].insert(jump - 1);
                    stone_map[next_pos].insert(jump);
                    stone_map[next_pos].insert(jump + 1);
                }
            }
        }

        return false;
    }
};

#if 0
/*
记忆化dfs

本质是把中间的计算结果保存下来，避免大量的重复计算，否则会超时！

就本题而言，哪些结果需要保存呢？跳k步，到达石头val，这种状态下如果不能到达终点，那么下次经过k步再次跳到石头val的时候，dfs就不要前进了。
也就是用 make_pair(val, k) 表示一种状态。

注意：pair<int, int>可以作为map的key，如果需要用作 unordered_map 的key，需要手动实现一个hash函数。
*/
class Solution {
private:
    unordered_set<int> vals; // 需要快速判断某个石头 val 是否存在
    map<pair<int, int>, bool> can_reach; // 只需记录不可达的状态，避免无效的计算。

public:
    bool canCross(vector<int>& stones)
    {
        int n = stones.size();

        if (n < 2)
            return true;
        else {
            if (stones[1] - stones[0] != 1)
                return false;
        }

        for (int i : stones) {
            vals.insert(i);
        }

        return dfs(stones.back(), stones[1], 1);
    }

    // 从上一跳跳了k步，跳入石头val，val不一定存在。
    bool dfs(int target, int val, int k)
    {
        if (val == target) {
            return true;
        }

        if (!vals.count(val))
            return false;

        // 查表，如果当前状态已经记录了不可达，直接返回false。
        auto key = make_pair(val, k);
        if (can_reach.count(key) && !can_reach[key]) {
            return false;
        }

        for (int i = k - 1; i <= k + 1; ++i) {
            if (i > 0) {
                if (dfs(target, val + i, i))
                    return true;
                else {
                    // 当前状态无法到达终点，记录下来，避免下次重复计算。
                    can_reach[make_pair(val + i, i)] = false;
                }
            }
        }

        return false;
    }
};
#endif
