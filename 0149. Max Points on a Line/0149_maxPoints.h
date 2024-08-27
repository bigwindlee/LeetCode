#pragma once
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/*
149. ֱ�������ĵ���
����һ������ points ������ points[i] = [xi, yi] ��ʾ X-Y ƽ���ϵ�һ���㡣������ж��ٸ�����ͬһ��ֱ���ϡ�

˼·������
  - ����ȷ��һ��ֱ�ߣ�������˫��ѭ����ö�����е�������ϡ�ֱ��û�з�������j��i+1��ʼ��
  - б��ͨ��Լ�֣�ת���ַ�����Ϊ��ϣ���key���������б�ʵ��µĸ������������⡣
  - ÿһ�ֶ�i��ö�ٽ����󣬶�Ҫ���ܲ������ϣ����Ϊͳ�Ƶ���ͨ��i��ġ���һ��ֱ���ϵ�j��������������ⲻͨ��i�㵫б����ͬ��ƽ������ɵĸ��š�
  - ����ʱҪ��i��Ҳ�����ڡ�
*/
class Solution_0149 {
public:
	int maxPoints(vector<vector<int>>& points) {
		int ans = 0;
		int n = points.size();
		unordered_map<string, int> m; // ͨ��i�������ֱ�ߵ�б�ʣ������б�ʽ���Ƶ��ͳ�ơ�
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int x = points[j][0] - points[i][0];
				int y = points[j][1] - points[i][1];

				// Լ�ֺ�ת���ַ�����Ϊ��ϣ���key������ֱ�Ӽ���б�ʵ��µĸ������������⡣
				int k = gcd(x, y);
				string key = to_string(x / k) + '_' + to_string(y / k);
				++m[key];
			}

			// ����ͨ��i���б��ͳ����ϣ�Ҫ���ܲ������ϣ��������Щ��ͨ��i�㵫��б��һ����ƽ������ɵĸ��š�
			for (const auto& [first, second] : m) {
				ans = max(ans, second);
			}
			m.clear();
		}

		// �������ansʵ������ͳ�Ƶ�һ��ֱ����j��ĸ�����Ҫ��i��Ҳ���ϡ�
		return ans + 1;
	}

	//  ŷ������㷨��Euclidean algorithm��`�������Լ��`
	int gcd(int a, int b) {
		return (b == 0) ? a : gcd(b, a % b);
	}
};