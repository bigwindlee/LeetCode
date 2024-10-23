#pragma once
#include "TreeNode.h"
#include <queue>
#include <sstream>
#include <string>
using namespace std;

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (!root) {
            return "X"; // 代表空指针
        }
        // 先序：根-左-右
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        queue<string> q; // 利用分隔符','拆分序列化的文本，放入队列。
        string node;
        stringstream ss(data);
        while (getline(ss, node, ',')) { // 知识点：getline
            q.push(node);
        }
        return buildTree(q);
    }

private:
    TreeNode* buildTree(queue<string>& nodes)
    {
        string node = nodes.front(); // 先序，队首是根节点
        nodes.pop();
        if (node == "X") {
            return nullptr;
        }
        // 递归构造子树
        TreeNode* root = new TreeNode(stoi(node));
        root->left = buildTree(nodes);
        root->right = buildTree(nodes);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));