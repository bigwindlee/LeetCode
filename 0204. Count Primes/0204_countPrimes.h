#pragma once
#include <vector>
using namespace std;

/*
204. 计数质数
给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。
*/

/*
思路分析：
    埃拉托斯特尼筛法（Sieve of Eratosthenes），该算法的时间复杂度为 O(n log log n)
    简称：埃氏筛
    本质上就是质数的倍数标记法
*/
class Solution {
public:
    int countPrimes(int n)
    {
        int ans = 0;

        // 标记数组：预设全部为质数，初始值2、3肯定是对的；
        // 后面的合数的质因数一定出现在前面，所以一定会作为质因数的倍数被标记，不会有遗漏！
        vector<bool> isPrime(n, true);

        for (long i = 2; i < n; ++i) { // 考虑到i*i可能溢出int，提前设置为long型。
            if (isPrime[i]) {
                ++ans;
                // 避免重复标记：从i的i倍开始，然后是(i+1)倍...
                for (long j = i * i; j < n; j += i) {
                    isPrime[j] = false; // 标记为`合数`
                }
            }
        }
        return ans;
    }
};