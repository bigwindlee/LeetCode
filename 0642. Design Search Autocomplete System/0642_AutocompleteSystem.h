#pragma once
#include <unordered_map>
#include <vector>
using namespace std;

class AutocompleteSystem {
public:
    // 定义 TrieNode 结构
    struct TrieNode {
        unordered_map<char, TrieNode*> children; // 子节点
        unordered_map<string, int> countMap; // 存储以当前节点为前缀的句子和对应的出现次数
    };

    AutocompleteSystem(vector<string>& sentences, vector<int>& times)
    {
        root = new TrieNode();
        currentNode = root;
        currentInput = "";
        // 初始化系统，将现有的句子及其出现次数插入 Trie
        for (int i = 0; i < sentences.size(); ++i) {
            insert(sentences[i], times[i]);
        }
    }

    vector<string> input(char c)
    {
        if (c == '#') {
            // 输入结束，将当前输入的句子插入 Trie
            insert(currentInput, 1);
            currentInput = "";
            currentNode = root;
            return {};
        }

        currentInput += c; // 更新当前输入
        if (currentNode && currentNode->children.count(c)) {
            currentNode = currentNode->children[c]; // 指向c字符的节点
        } else {
            currentNode = nullptr; // 没有找到匹配的前缀
            return {};
        }

        // 取得以当前前缀为开头的所有句子，并按要求排序
        return getTop3Matches();
    }

private:
    TrieNode* root;
    TrieNode* currentNode; // 最近输入的字符节点，查询下个输入字符的起点；遇到'#'回归root
    string currentInput; // 输入字符的累加；遇到'#'清空

    // 插入一个句子并更新次数
    void insert(const string& sentence, int count)
    {
        TrieNode* node = root;
        for (char c : sentence) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->countMap[sentence] += count;
        }
    }

    // 获取当前前缀下的所有句子，并返回前 3 个
    vector<string> getTop3Matches()
    {
        vector<pair<string, int>> results;
        for (const auto& [sentence, count] : currentNode->countMap) {
            results.push_back({ sentence, count });
        }

        // 排序规则：按次数降序，如果次数相同则按字典顺序升序
        sort(results.begin(), results.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });

        // 选取前 3 个句子
        vector<string> top3;
        for (int i = 0; i < min(3, (int)results.size()); ++i) {
            top3.push_back(results[i].first);
        }
        return top3;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */