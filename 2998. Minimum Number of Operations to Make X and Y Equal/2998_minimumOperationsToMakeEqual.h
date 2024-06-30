#pragma once
#include <unordered_map>
using namespace std;

/*
带记忆化的回溯法
但凡见到这种有多条通路可以选择去到达一个终点，求最短的路径，或者求一共有多少条路径的算法题，都要考虑回溯法。
回溯法，本质上都是在循环中调用递归来遍历所有解空间。要考虑是否有优化的可能：
    1）带记忆化的回溯法，把计算结果存起来，避免重复的计算；
    2）遍历所有解空间的过程中，是否可以剪枝，避免无效的计算；

难点：
在循环中递归，一定要注意递归能否收敛，否则会陷入无限递归的境地。
本题给出的4个搜索方向，其中`+1`操作的搜索路径会导致x无限增大，递归没有出口。
因此要重新规划出`可收敛`的搜索方向。考虑到`除法`对x的影响会远大于加一减一，所有本题的搜索方向是x向上或向下寻找5或11整数倍数，通过除法快速的收敛，避免无限递归。
重新规划搜索方向：
1）x向下寻找11的倍数，x%11是x到达11的倍数所需的`-1`操作次数；
2）x向上寻找11的倍数，(11 - x%11)是x到达11的倍数所需的`+1`操作次数；
3）x向下寻找5的倍数，x%5是x到达5的倍数所需的`-1`操作次数；
4）x向上寻找5的倍数，(11 - x%5)是x到达5的倍数所需的`+1`操作次数；

使用回溯法，一定要注意循环中的递归是否`可收敛`。

知识点：
    从 C++11 开始，std::min 和 std::max 可以接受 std::initializer_list 作为参数。
*/
class Solution_2998 {
public:
    int minimumOperationsToMakeEqual(int x, int y)
    {
        // 剪枝，递归出口。
        // x < y，意味着x只能通过`+1`操作去达到y，没有其它的通路。
        if (x <= y)
            return y - x;

        // 记忆化
        if (memo.find(x) != memo.end())
            return memo[x];

        // 沿着4个搜索方向去遍历解空间，可以看到4个方向的x都是收敛的（通过除法）。
        return memo[x] = min({ x - y, // x>y的情况下，一条简单的通路是通过`-1`操作到达y，也就是最多需要x-y次操作。
                   minimumOperationsToMakeEqual(x / 11, y) + x % 11 + 1,
                   minimumOperationsToMakeEqual(x / 11 + 1, y) + (11 - x % 11) + 1,
                   minimumOperationsToMakeEqual(x / 5, y) + x % 5 + 1,
                   minimumOperationsToMakeEqual(x / 5 + 1, y) + (5 - x % 5) + 1 });
    }

private:
    unordered_map<int, int> memo; // 实现记忆化搜索需要的存储
};