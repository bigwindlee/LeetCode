#pragma once
#include <algorithm>
#include <climits>
using namespace std;

/*  
思路1：质因数分解
把所有质因数加起来。
*/
class Solution {
public:
    int minSteps(int n)
    {
        if (n == 1) {
            return 0;
        }
        int ans = 0;
        // 先尝试较小的i，以满足`最少操作次数`。
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                ans += i; // i为粘贴次数；i越小，操作次数越少。
                n /= i;
            }
        }
        // 此时n要么是1，要么是一个质数；
        if (n > 1) {
            ans += n;
        }
        return ans;
    }
};

/*
思路2：DFS
采用DFS暴力搜索，有2个搜索方向：
    1）粘贴上一次剪贴板里面的内容：cur + step
    2）把当前内容刷新到剪贴板(Copy All)，再粘贴：cur * 2

要点：
    1）本题的DFS通过返回值累加，需要考虑剪枝的时候，返回值怎么处理：使用-1通知父节点进行剪枝。

*/
class Solution_2 {
public:
    int minSteps(int n)
    {
        if (n == 1) {
            return 0;
        }
        // 初始状态剪贴板为空，需要1次粘贴操作
        return 1 + dfs(n, 1, 1);
    }

    int dfs(int n, int cur, int step)
    {
        if (cur == n) {
            return 0;
        } else if (cur > n) {
            return -1; // DFS不可达，使用-1通知父节点进行剪枝
        }

        int a = dfs(n, cur + step, step);
        int b = dfs(n, cur * 2, cur);
        if (a < 0 && b < 0) { // 左右子树都不可达
            return -1; // 通知父节点剪枝
        } else if (a < 0) {
            return 2 + b; // 把当前内容刷新到剪贴板(Copy All)，再粘贴；2次操作；
        } else if (b < 0) {
            return 1 + a; // 粘贴上一次剪贴板里面的内容，1次操作；
        }
        return min(2 + b, 1 + a);
    }
};