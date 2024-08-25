#pragma once
#include <vector>
using namespace std;

/*
48. 旋转图像
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

思路分析：
所谓的原地旋转，就是要通过交换数组元素的位置来完成。
顺时针旋转90度，可以通过2次交换完成：
1）沿对角线交换（左上 -- 右下）
2）沿垂直中线交换
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        // 第一次交换：沿着（左上 -- 右下）的对角线交换
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 第二次交换：沿着垂直中线交换。要小心j的变化范围。
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};