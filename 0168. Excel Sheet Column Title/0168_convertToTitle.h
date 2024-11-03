#pragma once
#include <string>
using namespace std;

/*
168. Excel 表列名称
给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
例如：
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
*/

/*
思路分析：26进制
*/
class Solution {
public:
    string convertToTitle(int columnNumber)
    {
        string ans;
        while (columnNumber) {
            ans.push_back((columnNumber - 1) % 26 + 'A'); // 顺序相反不用怕，一会儿reverse
            columnNumber = (columnNumber - 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
