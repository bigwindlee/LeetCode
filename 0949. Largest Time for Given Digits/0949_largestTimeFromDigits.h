#pragma once
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
�������(backtrack)����ȫ����������ֵ��

�Ż�˼·����arr�������У���ô���ݷ��ҵ��ĵ�һ����������մ𰸣�

֪ʶ�㣺
1��ע�⾭�����ȫ���еı���ģ�壻
2����׼��ĺ���sort��Ҫͷ�ļ�<algorithm>��Ĭ��Ϊ�������У�
3��vector�Ĺ��캯��֮һ��explicit vector (size_type n, const value_type& val = value_type(), ...);
4��string�ķ�����substr / push_back / pop_back

*/
class Solution_0949_2 {
public:
    string largestTimeFromDigits(vector<int>& arr)
    {
        vector<bool> used(4, false); // ����Ԫ�ظ���Ϊ4����ֵΪfalse��vector<bool>
        string time;
        string ans;

        sort(arr.begin(), arr.end(), greater<int>()); // �Ż����������к󣬻��ݷ��ҵ��ĵ�һ����������մ𰸣�
        backtrack(arr, used, time, ans);
        return ans;
    }

    void backtrack(const vector<int>& arr, vector<bool>& used, string& time, string& ans)
    {
        if (ans.length() > 0) {
            return; // ��֦���������к󣬻��ݷ��ҵ��ĵ�һ����������մ𰸣�
        }
        if (time.size() == 4) {
            string hh = time.substr(0, 2);
            string mm = time.substr(2, 2);
            if (hh < "24" && mm < "60") {
                ans = hh + ":" + mm;
            }
            return;
        }

        // �������ģ��
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
������ݣ���ȫ����������ֵ��
δ�Ż��汾
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
            if (hh < "24" && mm < "60" && current > ans) { // δ�Ż��汾����ȫ������Ѱ����ֵ
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
