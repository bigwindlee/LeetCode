#pragma once
#include <string>
using namespace std;

/*
796. 旋转字符串
给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。
s 的 旋转操作 就是将 s 最左边的字符移动到最右边。 
例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。

思路分析：
常规解法：
    定义一个比较函数，从字符串s的start起点开始，和goal字符串中的字符逐一比较，s的下标到达末尾后，在轮回到s的下标起点。用`取余`操作计算下标。
    枚举字符串s的下标，作为起点start和goal进行比较。发现字符串相等立即返回。
技巧性解法：
    如果旋转后相等，那么(s+s)一定包含goal！这样只需要一次find操作！

知识点：
    std::string的find方法；常量string::npos
*/
class Solution_0796_2 {
public:
    // 技巧性解法：如果旋转后相等，那么(s+s)一定包含goal！这样只需要一次find操作！
    bool rotateString(string s, string goal)
    {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};

class Solution_0796_1 {
public:
    // 常规解法：枚举s的每一个下标作为和goal比较的起点。
    bool rotateString(string s, string goal)
    {
        int n = s.size();
        if (n != goal.size()) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            if (cmpString(s, i, goal)) {
                return true;
            }
        }
        return false;
    }

    // 常规解法的比较函数：设定比较的起点start，利用`取余`操作计算下标。
    bool cmpString(string s, int start, string goal)
    {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int j = (i + start) % n;
            if (s[j] != goal[i]) {
                return false;
            }
        }
        return true;
    }
};
