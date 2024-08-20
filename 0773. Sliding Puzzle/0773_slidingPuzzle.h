#pragma once
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/*
773. ��������
��һ�� 2 x 3 �İ��ϣ�board���� 5 ��ש�ߣ������� 1~5 ����ʾ, �Լ�һ���ȱ�� 0 ����ʾ��һ�� �ƶ� ����Ϊѡ�� 0 ��һ�����ڵ����֣��������ң����н���.
���յ��� board �Ľ���� [[1,2,3],[4,5,0]] �հ屻�⿪��
����һ���հ�ĳ�ʼ״̬ board ���������ٿ���ͨ�����ٴ��ƶ��⿪�հ壬������ܽ⿪�հ壬�򷵻� -1 ��

˼·������
���������·�����������ٲ��衱����Ҫ���뵽BFS�㷨��
BFS ��һ��ͨ����α����ķ�ʽ̽�������ռ���㷨���ر��ʺ�����������·�����⡣�ڻ��������У�����ͨ�� BFS ϵͳ�س������п��ܵ�״̬ת����ֱ���ҵ����Ž⡣
ÿһ���ĺ����������ö��й��������״̬�����÷��ʼ�¼�����ظ�������ÿ����չ�ھӽڵ�ʱ�ж��Ƿ�ﵽ��Ŀ��״̬��

�ѵ㣺
�Ѷ�ά����ת����string���������ά����neighbors��ʾ�ƶ�����ÿ���ƶ����򶼹��ɵ�ǰ�ڵ���ھӽڵ㡣
BFS�㷨��Ҫ��֮һ���Ӷ��е�����ǰ�ڵ��Ҫ��չ�ھӽڵ㲢������У��������ܱ�����ÿһ����Ρ�
*/
class Solution_0773 {
public:
    // �����ƶ���������飬��ʾÿ��λ�ÿ��ܵĽ���
    vector<vector<int>> neighbors = {
        { 1, 3 }, // λ��0���Ժ�λ��1��3����
        { 0, 2, 4 }, // λ��1���Ժ�λ��0��2��4����
        { 1, 5 }, // λ��2���Ժ�λ��1��5����
        { 0, 4 }, // λ��3���Ժ�λ��0��4����
        { 1, 3, 5 }, // λ��4���Ժ�λ��1��3��5����
        { 2, 4 } // λ��5���Ժ�λ��2��4����
    };

    int slidingPuzzle(vector<vector<int>>& board)
    {
        string start, target = "123450";

        // ����ʼ״̬ת��Ϊ�ַ���
        for (auto& row : board) {
            for (auto& num : row) {
                start.push_back('0' + num);
            }
        }

        // �����ʼ״̬����Ŀ��״̬��ֱ�ӷ���0
        if (start == target)
            return 0;

        // BFS ����
        queue<pair<string, int>> q;
        q.push({ start, 0 });

        // ��¼���ʹ���״̬
        unordered_set<string> visited;
        visited.insert(start);

        while (!q.empty()) {
            auto [current, step] = q.front(); // �˴�����ʹ��auto&����Ϊ������pop()�����������Ķ���
            q.pop(); // This calls the removed element's destructor.

            int zeroPos = current.find('0');

            // �����ƶ� '0' �����ܵķ���ÿһ�����ܵķ��򶼹����ھӽڵ㡣
            for (int neighbor : neighbors[zeroPos]) {
                string newBoard = current;
                swap(newBoard[zeroPos], newBoard[neighbor]);

                // ����õ���Ŀ��״̬�����ز���
                if (newBoard == target)
                    return step + 1;

                // ����µ�״̬û�з��ʹ�����������
                if (!visited.count(newBoard)) {
                    visited.insert(newBoard);
                    q.push({ newBoard, step + 1 });
                }
            }
        }

        // �޷��⿪����
        return -1;
    }
};