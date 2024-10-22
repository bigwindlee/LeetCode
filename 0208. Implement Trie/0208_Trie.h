#pragma once
#include <string>
#include <unordered_map>
using namespace std;

/*
208. 实现 Trie (前缀树)
前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。
请你实现 Trie 类：
  ● Trie() 初始化前缀树对象。
  ● void insert(String word) 向前缀树中插入字符串 word 。
  ● boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
  ● boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
*/

/*
思路分析：前缀树
*/
class Trie {
public:
    Trie()
    {
        root = new TrieNode(); // 根节点是空的，不代表任何字符。
    }

    void insert(string word)
    {
        TrieNode* p = root;
        for (char c : word) {
            if (p->children.count(c) == 0) {
                p->children[c] = new TrieNode();
            }
            p = p->children[c];
        }
        p->isEnd = true; // p指向word的末字符
    }

    bool search(string word)
    {
        TrieNode* p = root;
        for (char c : word) {
            if (p->children.count(c) == 0) {
                return false;
            }
            p = p->children[c];
        }
        return p->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode* p = root;
        for (char c : prefix) {
            if (p->children.count(c) == 0) {
                return false;
            }
            p = p->children[c];
        }
        return true;
    }

private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children; // 前缀树核心数据结构
        bool isEnd; // word的末字符标志
        TrieNode(bool end = false)
            : isEnd(end)
        {
        }
    };
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
