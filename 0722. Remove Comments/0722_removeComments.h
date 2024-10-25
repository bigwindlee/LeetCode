#pragma once
#include <string>
#include <vector>
using namespace std;
/*
使用两个变量：inBlockComment 表示是否在多行注释中，newLine 用于构建当前行的内容。
遍历每一行源代码，逐个字符处理：
    - 如果遇到`多行注释开始标志`，则进入多行注释模式。
    - 如果遇到`多行注释结束标志`，则退出多行注释模式。
    - 如果遇到 //，则忽略该行后面的内容。
    - 如果不在注释中，则将字符添加到 newLine 中。
如果当前行不在注释中且 newLine 非空，则将其添加到结果中。
返回处理后的代码行。

本题关键是理解4中状态：
1）进入多行注释模式；
2）退出多行注释模式；
3）遇单行注释符，提前结束一行的扫描；
4）当前非注释，逐个字符收集；
*/

class Solution {
public:
    vector<string> removeComments(vector<string>& source)
    {
        vector<string> ans;
        bool inBlockComment = false; // 当前是否在多行注释模式中
        string newLine; // 逐个字符收集每一行的非注释内容

        for (const string& line : source) {
            // 只有在非多行注释模式中，才能清空newLine；
            // 因为在多行注释模式中，newLine可能包含有效的代码，而且还没有收集完毕，可能要跨行收集。（参见官方case2）
            if (!inBlockComment) {
                newLine = "";
            }
            for (int i = 0; i < line.length(); ++i) { // 逐个字符扫描
                if (!inBlockComment && line.substr(i, 2) == "/*") {
                    inBlockComment = true;
                    ++i;
                } else if (inBlockComment && line.substr(i, 2) == "*/") {
                    inBlockComment = false;
                    ++i;
                } else if (!inBlockComment && line.substr(i, 2) == "//") {
                    break; // 只有遇到单行注释符，才能提前结束一行的扫描；
                } else if (!inBlockComment) {
                    newLine += line[i]; // 逐个字符收集；在遇到多行注释时，可能要跨行收集；
                }
            }

            if (!inBlockComment && !newLine.empty()) {
                ans.push_back(newLine);
            }
        }

        return ans;
    }
};
