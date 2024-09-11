#pragma once
#include <vector>
using namespace std;

/*
* 1310. 子数组异或查询
有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。
对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]）作为本次查询的结果。
并返回一个包含给定查询 queries 所有结果的数组。
*/

/*
思路分析：（前缀异或）
前缀和的思想可以推广到异或操作；
*/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }

        n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (queries[i][0] == 0)
                ans[i] = prefix[queries[i][1]];
            else
                ans[i] = prefix[queries[i][1]] ^ prefix[queries[i][0] - 1];
        }
        return ans;
    }
};