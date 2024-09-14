### 给字符串添加加粗标签 - 核心要点总结

#### 题目描述
给定字符串 `s` 和字符串数组 `words`，需要将 `s` 中出现的 `words` 子串加上粗体标签 `<b>` 和 `</b>`。如果多个子串重叠或者相邻，需要合并为一个粗体标签区间。

#### 解决思路
1. **区间标记**： 
   - 创建一个与字符串 `s` 等长的布尔数组 `bold`，初始值为 `false`，表示字符不加粗。
   - 遍历 `words` 中的每个子串，找到它们在 `s` 中的所有出现位置，将相应的区间标记为 `true`。
   
2. **合并区间**：
   - 在构建结果字符串时，检测布尔数组 `bold` 中相邻或重叠的 `true` 区间，合并为一个 `<b>` 标签包裹的部分。
   
3. **时间复杂度**：
   - 查找每个子串的时间复杂度为 `O(n * m)`，其中 `n` 为字符串 `s` 的长度，`m` 为 `words` 中最长单词的长度。

#### 代码实现（C++）
```cpp
string boldWords(vector<string>& words, string s)
{
	int n = s.size();
	vector<bool> bold(n, false);

	// 标记需要加粗的字符
	for (const string& word : words) {
		int pos = s.find(word);
		while (pos != string::npos) {
			fill(bold.begin() + pos, bold.begin() + pos + word.size(), true); // 染色
			pos = s.find(word, pos + 1);
		}
	}

	// 构建结果字符串
	string ans;
	for (int i = 0; i < n; ++i) {
		if (bold[i] && (i == 0 || !bold[i - 1])) { // 被染色区间的左边界
			ans += "<b>";
		}
		ans += s[i];
		if (bold[i] && (i == n - 1 || !bold[i + 1])) { // 被染色区间的右边界
			ans += "</b>";
		}
	}

	return ans;
}
```