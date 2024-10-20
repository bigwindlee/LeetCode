#pragma once
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Excel {
public:
    // 初始化 Excel
    Excel(int height, char width)
    {
        this->rows = height;
        this->cols = width - 'A' + 1;
        mat = vector<vector<int>>(rows, vector<int>(cols, 0));
        sumFormulas = unordered_map<string, vector<string>>();
        dependencies = unordered_map<string, std::set<string>>();
    }

    // 设置单元格的值
    void set(int row, char column, int val)
    {
        string cell = getCell(row, column);
        sumFormulas.erase(cell); // 清除之前的求和公式
        dependencies[cell].clear(); // 清除依赖关系
        mat[row - 1][column - 'A'] = val;
        updateDependentCells(cell);
    }

    // 获取单元格的值
    int get(int row, char column)
    {
        return mat[row - 1][column - 'A'];
    }

    // 将单元格设置为求和公式并返回该单元格的值
    int sum(int row, char column, const vector<string>& numbers)
    {
        string cell = getCell(row, column);
        sumFormulas[cell] = numbers; // 存储求和公式
        dependencies[cell].clear(); // 清除之前的依赖关系
        int sumValue = calculateSum(numbers, cell);
        mat[row - 1][column - 'A'] = sumValue;
        updateDependentCells(cell); // 更新依赖的单元格
        return sumValue;
    }

private:
    int rows, cols;
    vector<vector<int>> mat;
    unordered_map<string, vector<string>> sumFormulas;
    unordered_map<string, std::set<string>> dependencies; // 要避免和自定义的set函数混淆，必须使用set

    // 将行列转换为字符串形式的单元格标识
    string getCell(int row, char column)
    {
        return column + to_string(row);
    }

    // 解析并计算求和公式的值
    int calculateSum(const vector<string>& numbers, const string& currentCell)
    {
        int total = 0;
        for (const auto& num : numbers) {
            if (num.find(':') < 0) {
                // 单个单元格，如 "A1"
                int row = stoi(num.substr(1));
                char col = num[0];
                dependencies[currentCell].insert(getCell(row, col));
                total += get(row, col);
            } else {
                // 范围单元格，如 "A1:B2"
                auto colonPos = num.find(':');
                string topLeft = num.substr(0, colonPos);
                string bottomRight = num.substr(colonPos + 1);

                int row1 = stoi(topLeft.substr(1));
                char col1 = topLeft[0];
                int row2 = stoi(bottomRight.substr(1));
                char col2 = bottomRight[0];

                for (int r = row1; r <= row2; ++r) {
                    for (char c = col1; c <= col2; ++c) {
                        dependencies[currentCell].insert(getCell(r, c));
                        total += get(r, c);
                    }
                }
            }
        }
        return total;
    }

    // 更新依赖于某个单元格的公式
    void updateDependentCells(const string& updatedCell)
    {
        for (const auto& [cell, deps] : dependencies) {
            if (deps.count(updatedCell)) {
                if (sumFormulas.count(cell)) {
                    int row = stoi(cell.substr(1));
                    char col = cell[0];
                    mat[row - 1][col - 'A'] = calculateSum(sumFormulas[cell], cell);
                    updateDependentCells(cell);
                }
            }
        }
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */