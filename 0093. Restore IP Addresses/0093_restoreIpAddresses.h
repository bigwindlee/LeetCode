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
        vector<string> path; //  保存ip地址的4个section，便于回溯撤销；

        function<void(int, int)> dfs = [&](int i, int deep) {
            int remain = s.size() - i; // 剩余字符数
            if (remain <= 0) {
                return;
            }

            // 最后一个section，递归出口。
            if (deep == 3) {
                // 剩余字符超过3个，或者包含前导0，不合法。
                if (remain > 3 || (remain > 1 && s[i] == '0')) {
                    return;
                }

                string section = s.substr(i, remain);
                if (stoi(section) > 255) {
                    return;
                }
                ans.push_back(path[0] + "." + path[1] + "." + path[2] + "." + section);
                return;
            }

            // IP地址每节长度为1~3，对应3个搜索方向：
            for (int len = 1; len <= min(3, remain); ++len) {
                if (len > 1 && s[i] == '0') {
                    break; // 前导0不合法
                }
                string section = s.substr(i, len);
                if (stoi(section) > 255) {
                    break;
                }
                path.push_back(section);
                dfs(i + len, deep + 1);
                path.pop_back(); // 回溯撤销
            }
        };

        dfs(0, 0);
        return ans;
    }
};