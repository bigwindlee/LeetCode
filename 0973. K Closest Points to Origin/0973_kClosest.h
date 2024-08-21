#pragma once
#include <queue>
#include <vector>
using namespace std;

/*
* 973. 最接近原点的 K 个点
给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点，并且是一个整数 k ，返回离原点 (0,0) 最近的 k 个点。
这里，平面上两点之间的距离是 欧几里德距离（ √(x1 - x2)2 + (y1 - y2)2 ）。
你可以按 任何顺序 返回答案。除了点坐标的顺序之外，答案 确保 是 唯一 的。

思路分析：（优先级队列）
经典TopK问题，用优先级队列解决。

知识点：
  - 自定义比较函数，使用lambda表达式，参数类型必须加`const`修饰。
  - 定义优先级队列需要的三个参数，都是类型，要用decltype提取自定义函数的类型！
        template<
            class T,
            class Container = std::vector<T>,
            class Compare = std::less<typename Container::value_type>
        > class priority_queue;
  - 访问堆顶元素使用top()方法，不要和queue的front()方法混淆！  
*/
class Solution_0973 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        // 自定义比较函数，lambda表达式。
        auto cmp = [](const vector<int>& p1, const vector<int>& p2) {
            return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]);
        };
        // 注意定义优先级队列需要的三个参数，要用decltype提取自定义函数的类型！
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q;
        for (auto& point : points) {
            if (q.size() < k) {
                q.push(point);
            } else {
                if (cmp(point, q.top())) { // 大顶堆，淘汰大的，留下的都是小的。
                    q.pop(); // 容量为k，因为是TopK问题。
                    q.push(point);
                }
            }
        }
        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};