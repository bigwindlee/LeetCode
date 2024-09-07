#pragma once
#include <unordered_map>
#include <vector>
using namespace std;

/* ------------------------------------------------------------------------------------------------
666. 路径总和 IV
对于一棵深度小于 5 的树，可以用一组三位十进制整数来表示。对于每个整数：
  ● 百位上的数字表示这个节点的深度 d，1 <= d <= 4。
  ● 十位上的数字表示这个节点在当前层所在的位置 P， 1 <= p <= 8。位置编号与一棵满二叉树的位置编号相同。
  ● 个位上的数字表示这个节点的权值 v，0 <= v <= 9。

给定一个包含三位整数的 升序 数组 nums ，表示一棵深度小于 5 的二叉树，请你返回 从根到所有叶子结点的路径之和 。
保证 给定的数组表示一个有效的连接二叉树。
*/

/* ------------------------------------------------------------------------------------------------
思路分析：（二叉树dfs递归 + 回溯）
技巧1：
  ● 节点值的前2位其实是一个二维坐标(节点的深度d，节点在当前层所在的位置p)
  ● 左右子节点可通过计算得到坐标（d坐标 + 1，p坐标 * 2）

技巧2：
  ● 利用哈希表存储节点从坐标到值的映射，还可用于判定左右子节点是否存在；

技巧3：
  ● 深入理解二叉树的递归和回溯。
  ● dfs前进过程中，把路径累计和复制并下发到左右子节点；在回溯过程中把所有叶子节点的路径累计和层层回馈给父节点；
*/
class Solution_0666 {
public:
    unordered_map<int, int> nodeValue; // 二叉树节点从位置到值的映射

    int pathSum(vector<int>& nums)
    {
        for (int num : nums) {
            nodeValue[num / 10] = num % 10; // 前2位表示一个二维坐标(节点的深度d，节点在当前层所在的位置p)
        }
        return dfs(nums[0] / 10, 0);
    }

    // node: 节点坐标
    // sum: 父节点下发的路径累计和
    int dfs(int node, int sum)
    {
        // 左右子节点坐标可通过当前节点坐标计算出来（d坐标 + 1，p坐标 * 2）
        int leftChild = (node / 10 + 1) * 10 + node % 10 * 2 - 1;
        int rightChild = leftChild + 1;

        bool hasLeft = nodeValue.count(leftChild) > 0;
        bool hasRight = nodeValue.count(rightChild) > 0;

        sum += nodeValue[node]; // 由父节点保证当前坐标node是有效坐标
        if (!hasLeft && !hasRight) {
            return sum;
        }
        // 当前路径累计和复制下发给子节点，并通过回溯归拢！
        return (hasLeft ? dfs(leftChild, sum) : 0) + (hasRight ? dfs(rightChild, sum) : 0);
    }
};
