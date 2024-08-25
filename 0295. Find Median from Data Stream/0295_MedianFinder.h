#pragma once
#include <queue>
#include <vector>
using namespace std;

/*
* 295. 数据流的中位数
中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
例如 arr = [2,3,4] 的中位数是 3 。
例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
实现 MedianFinder 类:
MedianFinder() 初始化 MedianFinder 对象。
void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。

思路分析：（优先级队列的思想）
数据加入的时候是无序的，加入后要求数据保存“动态有序”，很显然要求使用优先级队列。
题目要求中位数，而且是动态的“中位数”，不能每加入一个值就要对所有值重新排序，技巧是把所有值分成两半保存。


把数据分成2部分，较小的一半保存在“小值堆”，较大的一半保存在“大值堆”。
很显然，小值堆要使用“大根堆”，大值堆要使用“小根堆”，这样才能使2个堆的堆顶值接近于“中位数”。

小值堆的size，和大值堆相等，或者比大值堆多一个（最多多一个）。超出的要挪到大值堆。

求中位数：
    当数据流元素数量为偶数：小值堆 和 大值堆 size相同，此时动态中位数为两者堆顶元素的平均值；
    当数据流元素数量为奇数：小值堆size 比 大值堆 多一，此时动态中位数为 小值堆 的堆顶原数。
*/
class MedianFinder {
public:
    // 小值堆要使用“大根堆”（默认就是），.top()是堆内最大值，联想less，表示弹出的越来越小；存储较小的一半元素，则堆顶就是中位数候选；
    priority_queue<int, vector<int>, less<int>> qMin;

    // 大值堆要使用“小根堆”，.top()是堆内最小值，联想greater，表示弹出的越来越大；存储较大一半元素，则堆顶就是中位数候选；
    priority_queue<int, vector<int>, greater<int>> qMax;

    MedianFinder() { }

    void addNum(int num)
    {
        if (qMin.empty() || num < qMin.top()) {
            // 进入小值堆的条件：小值堆为空，或者当前数字 <= 小值堆堆顶元素
            qMin.push(num);

            // 小值堆的size变大了，但是最多只能比大值堆多一个。超出则把堆顶挪到大值堆。
            if (qMin.size() > qMax.size() + 1) {
                qMax.push(qMin.top());
                qMin.pop();
            }
        } else {
            // 进入大值堆
            qMax.push(num);

            // 大值堆的size变大了，但是不能超过小值堆。超出则把堆顶挪到小值堆。
            if (qMax.size() > qMin.size()) {
                qMin.push(qMax.top());
                qMax.pop();
            }
        }
    }

    // 当数据流元素数量为偶数：小值堆 和 大值堆 size相同，此时动态中位数为两者堆顶元素的平均值；
    // 当数据流元素数量为奇数：小值堆size 比 大值堆 多一，此时动态中位数为 小值堆 的堆顶原数。
    double findMedian()
    {
        if (qMin.size() > qMax.size()) {
            return qMin.top();
        }
        return (qMin.top() + qMax.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */