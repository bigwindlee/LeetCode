#pragma once
#include "TreeNode.h"
#include <vector>
using namespace std;

/*
971. ��ת��������ƥ���������
����һ�ö������ĸ��ڵ� root �������� n ���ڵ㣬ÿ���ڵ㶼��һ����ͬ�������ڵ��Ҵ��� 1 �� n ֮���ֵ��
�����һ���� n ��ֵ��ɵ��г����� voyage ����ʾ Ԥ�� �Ķ����� ������� �����
ͨ�������ڵ���������������� ��ת �ö������е�����ڵ㡣
�뷭ת ���� �����нڵ㣬ʹ�������� ������� ��Ԥ�ڵı����г� voyage ��ƥ�� �� 
������ԣ��򷵻� ��ת�� ���нڵ��ֵ���б�����԰��κ�˳�򷵻ش𰸡�������ܣ��򷵻��б� [-1]��

˼·������
�����������������Ҳ�����ȸ�������һ���ǡ���-��-�ҡ���˳�򡣱���ĺ�������ĳЩ�����»��ɡ���-��-�󡱵�˳��
Ҫ�������˳���������������ƥ�䣬��ô��Ҫ�ж�ʲôʱ�򻻳ɡ���-��-�󡱵�˳��

���ɣ�
1. �������������dfs�ķ������Ͷ���Ϊbool�����������жϱ����Ĺ����У��Ƿ�͸�����������ƥ�䣡
2. ע�⻻�ɡ���-��-�󡱵�˳��Ҫ�����������
    1����ڵ㲻Ϊ�գ���Ϊ��ڵ�Ϊ�յĻ�������Ҫ�������ҽڵ㣬�ʹﵽ����-�ҡ���˳��
    2���ҽڵ㲻Ϊ�գ���ֵ�� voyage ��ƥ�䣬��ʱ��Ҫ�������ҽڵ㣬����ʹ�������������Ԥ�ڵı����г� voyage ��ƥ�䣻
3. ��Ҫ��dfs�ⲿ�ж���ڵ�ֵ�Ƿ�ƥ�䣬���Ƿŵ�dfs�ڲ����������߼�Ҳ���ϸ��ڵ㣻
4. ��Ҫһ��ȫ��ָ��ԡ����������顱����ɨ�衣

*/
class Solution_0971 {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage)
    {
        if (!root) {
            return { -1 };
        }
        i = 0; // ȫ��ָ��ɨ��voyage
        vector<int> ans;
        if (dfs(root, voyage, ans)) {
            return ans;
        } else {
            return { -1 };
        }
    }

    bool dfs(TreeNode* root, vector<int>& voyage, vector<int>& ans)
    {
        if (!root) { // �ܹ��ܿ��ڵ�ֵ��ƥ��������˳�����ס�
            return true;
        }
        if (root->val != voyage[i++]) { // �жϽڵ�ֵ�Ƿ�ƥ�䣬ͬ���ʺϸ��ڵ㣡
            return false;
        }
        // ��ڵ㲻Ϊ��ʱ������Ҫ�������ҽڵ㡣
        if (root->left && root->right && root->right->val == voyage[i]) {
            ans.push_back(root->val);
            return dfs(root->right, voyage, ans) && dfs(root->left, voyage, ans);
        }
        // ��Ҫ��dfs�ⲿ�ж���ڵ�ֵ�Ƿ�ƥ�䣬���Ƿŵ�dfs�ڲ����������߼�Ҳ���ϸ��ڵ㣻
        // ������ڵ�ĵ�������
        return dfs(root->left, voyage, ans) && dfs(root->right, voyage, ans);
    }
    int i;
};
