#pragma once
#include <functional>
#include <string>
#include <vector>
using namespace std;

/*
回溯法（在循环中递归，遍历所有解空间。）
用dfs的思想来理解，就是每一次循环，都是一个搜索的方向。

ip地址是用'.'分割的4个section，每次从字符串头部剥离一个合法的section，剩下的交给递归函数去做。
deep表示当前要剥离的section编号，取值范围：0/1/2/3。
deep == 3 为最后一个section，也就是递归的出口。

*/

class Solution_0093 {
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        vector<string> path; // 保存试探过程中的每一节ip地址，使用vector便于撤销；

        function<void(int, int)> dfs = [&](int i, int deep) {
            // Step 1: 剪枝不合法的搜索路径
            int remain = s.size() - i; // 剩余字符数
            if (remain <= 0) {
                return;
            }

            // Step 2: 如何判断到达叶子节点（递归出口）：固定搜索深度使用depth递减；
            if (deep == 3) {
                if (remain > 3 || (remain > 1 && s[i] == '0')) {
                    return;
                }
                string section = s.substr(i, remain);
                if (stoi(section) > 255) {
                    return;
                }
                // 收集合法IP地址
                ans.push_back(path[0] + "." + path[1] + "." + path[2] + "." + section);
                return;
            }

            // Step 3: 穷举搜索方向
            for (int len = 1; len <= min(3, remain); ++len) {
                string section = s.substr(i, len); // 试探性取得一节IP地址
                if (len > 1 && s[i] == '0') {
                    break;
                }
                if (stoi(section) > 255) {
                    break;
                }
                path.push_back(section); // 试探性收集一节IP地址
                dfs(i + len, deep + 1); // 深度搜索
                path.pop_back(); // 回溯撤销
            }
        };

        dfs(0, 0);
        return ans;
    }
};