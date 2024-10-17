#pragma once
#include <stack>
#include <string>
using namespace std;

/*
71. 简化路径
给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为 更加简洁的规范路径。

在 Unix 风格的文件系统中规则如下：
  ● 一个点 '.' 表示当前目录本身。
  ● 此外，两个点 '..' 表示将目录切换到上一级（指向父目录）。
  ● 任意多个连续的斜杠（即，'//' 或 '///'）都被视为单个斜杠 '/'。
  ● 任何其他格式的点（例如，'...' 或 '....'）均被视为有效的文件/目录名称。

返回的 简化路径 必须遵循下述格式：
  ● 始终以斜杠 '/' 开头。
  ● 两个目录名之间必须只有一个斜杠 '/' 。
  ● 最后一个目录名（如果存在）不能 以 '/' 结尾。
  ● 此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。

返回简化后得到的 规范路径 。
*/

/*
思路分析：双指针 + 栈
  ● 需要界定由'/'分割的segment；很容易联系到双指针；
  ● 两个点 '..' 表示将目录切换到上一级，很容易联想到栈；

要点：
  ● 要考虑能否使用vector模拟stack的功能，尤其是需要正访问stack中的元素；
*/
class Solution {
public:
    string simplifyPath(string path)
    {
        string ans;
        vector<string> stk; // 两个点 '..' 表示将目录切换到上一级，此处用vector模拟栈的弹出功能。
        path.push_back('/'); // path不一定以'/'结尾，此处添加一个'/'，便于统一处理。
        int n = path.size(), last = 0, cur; // 双指针，界定由'/'分割的segment。
        while (last < n) {
            while (path[last] == '/') { // last指向'/'之后的首个非'/'字符
                ++last;
            }
            if (last == n) {
                break;
            }
            cur = path.find('/', last + 1); // cur指向last之后的'/'
            string segment = path.substr(last, cur - last); // 双指针，界定由'/'分割的segment。
            if (segment == "..") {
                if (!stk.empty()) {
                    stk.pop_back(); // 用vector模拟stack的功能
                }
            } else {
                if (segment != ".") {
                    stk.push_back(segment);
                }
            }

            last = cur;
        }

        for (string s : stk) { // stack不能由底向上的访问元素，此处vector的好处体现出来了。
            ans += string("/") + s;
        }
        return ans.empty() ? "/" : ans; // 要考虑stk为空的情况
    }
};