#pragma once
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/*
149. 直线上最多的点数
给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。

思路分析：
  - 两点确定一条直线，所以用双重循环，枚举所有的两两组合。直线没有方向，所以j从i+1开始。
  - 斜率通过约分，转成字符串作为哈希表的key，避免计算斜率导致的浮点数进度问题。
  - 每一轮对i的枚举结束后，都要归总并清零哈希表。因为统计的是通过i点的、在一条直线上的j点的最大个数。避免不通过i点但斜率相同的平行线造成的干扰。
  - 返回时要把i点也算在内。
*/
class Solution_0149 {
public:
	int maxPoints(vector<vector<int>>& points) {
		int ans = 0;
		int n = points.size();
		unordered_map<string, int> m; // 通过i点的所有直线的斜率，对这个斜率进行频率统计。
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int x = points[j][0] - points[i][0];
				int y = points[j][1] - points[i][1];

				// 约分后转成字符串作为哈希表的key，避免直接计算斜率导致的浮点数精度问题。
				int k = gcd(x, y);
				string key = to_string(x / k) + '_' + to_string(y / k);
				++m[key];
			}

			// 所有通过i点的斜率统计完毕，要归总并清零哈希表。避免那些不通过i点但是斜率一样的平行线造成的干扰。
			for (const auto& [first, second] : m) {
				ans = max(ans, second);
			}
			m.clear();
		}

		// 到这里的ans实际上是统计的一条直线上j点的个数，要把i点也算上。
		return ans + 1;
	}

	//  欧几里得算法（Euclidean algorithm）`计算最大公约数`
	int gcd(int a, int b) {
		return (b == 0) ? a : gcd(b, a % b);
	}
};