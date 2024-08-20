#pragma once
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/*
773. 滑动谜题
在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示。一次 移动 定义为选择 0 与一个相邻的数字（上下左右）进行交换.
最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。
给出一个谜板的初始状态 board ，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。

思路分析：
见到“最短路径”、“最少步骤”，就要联想到BFS算法。
BFS 是一种通过层次遍历的方式探索搜索空间的算法，特别适合用于求解最短路径问题。在滑动谜题中，我们通过 BFS 系统地尝试所有可能的状态转换，直到找到最优解。
每一步的核心在于利用队列管理待处理状态，利用访问记录避免重复，并在每次扩展邻居节点时判断是否达到了目标状态。

难点：
把二维数组转换成string，并定义二维数组neighbors表示移动方向。每个移动方向都构成当前节点的邻居节点。
BFS算法的要点之一：从队列弹出当前节点后，要扩展邻居节点并加入队列，这样才能遍历到每一个层次。
*/
class Solution_0773 {
public:
    // 定义移动方向的数组，表示每个位置可能的交换
    vector<vector<int>> neighbors = {
        { 1, 3 }, // 位置0可以和位置1、3交换
        { 0, 2, 4 }, // 位置1可以和位置0、2、4交换
        { 1, 5 }, // 位置2可以和位置1、5交换
        { 0, 4 }, // 位置3可以和位置0、4交换
        { 1, 3, 5 }, // 位置4可以和位置1、3、5交换
        { 2, 4 } // 位置5可以和位置2、4交换
    };

    int slidingPuzzle(vector<vector<int>>& board)
    {
        string start, target = "123450";

        // 将初始状态转换为字符串
        for (auto& row : board) {
            for (auto& num : row) {
                start.push_back('0' + num);
            }
        }

        // 如果初始状态就是目标状态，直接返回0
        if (start == target)
            return 0;

        // BFS 队列
        queue<pair<string, int>> q;
        q.push({ start, 0 });

        // 记录访问过的状态
        unordered_set<string> visited;
        visited.insert(start);

        while (!q.empty()) {
            auto [current, step] = q.front(); // 此处不能使用auto&，因为随后调用pop()会析构弹出的对象。
            q.pop(); // This calls the removed element's destructor.

            int zeroPos = current.find('0');

            // 尝试移动 '0' 到可能的方向，每一个可能的方向都构成邻居节点。
            for (int neighbor : neighbors[zeroPos]) {
                string newBoard = current;
                swap(newBoard[zeroPos], newBoard[neighbor]);

                // 如果得到了目标状态，返回步数
                if (newBoard == target)
                    return step + 1;

                // 如果新的状态没有访问过，则加入队列
                if (!visited.count(newBoard)) {
                    visited.insert(newBoard);
                    q.push({ newBoard, step + 1 });
                }
            }
        }

        // 无法解开谜题
        return -1;
    }
};