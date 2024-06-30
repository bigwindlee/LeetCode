#pragma once
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
经典回溯(backtrack)：从全排列中找最值。

优化思路：把arr降序排列，那么回溯法找到的第一个解就是最终答案！

知识点：
1）注意经典回溯全排列的编码模板；
2）标准库的函数sort需要头文件<algorithm>，默认为升序排列；
3）vector的构造函数之一：explicit vector (size_type n, const value_type& val = value_type(), ...);
4）string的方法：substr / push_back / pop_back

*/
class Solution_0949_2 {
public:
    string largestTimeFromDigits(vector<int>& arr)
    {
        vector<bool> used(4, false); // 构造元素个数为4个，值为false的vector<bool>
        string time;
        string ans;

        sort(arr.begin(), arr.end(), greater<int>()); // 优化：降序排列后，回溯法找到的第一个解就是最终答案！
        backtrack(arr, used, time, ans);
        return ans;
    }

    void backtrack(const vector<int>& arr, vector<bool>& used, string& time, string& ans)
    {
        if (ans.length() > 0) {
            return; // 剪枝：降序排列后，回溯法找到的第一个解就是最终答案！
        }
        if (time.size() == 4) {
            string hh = time.substr(0, 2);
            string mm = time.substr(2, 2);
            if (hh < "24" && mm < "60") {
                ans = hh + ":" + mm;
            }
            return;
        }

        // 经典回溯模板
        for (int i = 0; i < 4; ++i) {
            if (!used[i]) {
                used[i] = true;
                time.push_back(arr[i] + '0');
                backtrack(arr, used, time, ans);
                time.pop_back();
                used[i] = false;
            }
        }
    }
};

/*
经典回溯：从全排列中找最值。
未优化版本
*/
class Solution_0949_1 {
public:
    string largestTimeFromDigits(vector<int>& arr)
    {
        vector<bool> used(4, false);
        string time;
        string ans;
        backtrack(arr, used, time, ans);
        return ans;
    }

    void backtrack(const vector<int>& arr, vector<bool>& used, string& time, string& ans)
    {
        if (time.size() == 4) {
            string hh = time.substr(0, 2);
            string mm = time.substr(2, 2);
            string current = hh + ":" + mm;
            if (hh < "24" && mm < "60" && current > ans) { // 未优化版本：从全排列中寻找最值
                ans = current;
            }
            return;
        }

        for (int i = 0; i < 4; ++i) {
            if (!used[i]) {
                used[i] = true;
                time.push_back(arr[i] + '0');
                backtrack(arr, used, time, ans);
                time.pop_back();
                used[i] = false;
            }
        }
    }
};
