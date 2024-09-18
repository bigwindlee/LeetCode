﻿#pragma once

/*
* 793. 阶乘函数后 K 个零
 f(x) 是 x! 末尾是 0 的数量。回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 。
  ● 例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。

给定 k，找出返回能满足 f(x) = k 的非负整数 x 的数量。
*/

/*
题意理解：在一个单调不连续递增区间内查找一个数字k是否存在。

核心概念：一个数的阶乘后有多少个零，这实际上取决于阶乘中的 5 的因子数量。
因为每个 10 是由 2 和 5 相乘得来的，而 2 的因子在阶乘中远多于 5，因此问题简化为寻找 5 的因子个数。

第一次满足5出现了k次的数字a，和第一次满足5出现k+1次的数字b，并且两者相减(b-a)，结果就是满足了5可以出现k次的数量了。

查找范围：
每5次数字过后，才会出现1次5，那么如果我们要寻找第一次出现了k次5的话，我们要查找围的范就是5k了。所以，我们的查找范围确定为[0, 5k]。
比如，我们要找k=1，即：第一次5出现的位置，那么我们的查找范围就是[0, 5]；如果k=2，二分法查找的范围就是[0，10]。

x!后面的0的个数是随着x的增大而增长的；但并不是线性连续增长，一定会出现跳涨：
例如：`20!`后面有4个0，`25!`后面有6个0，如果k=5是没有解的。

规律：
这个题的答案不是0就是5，所以，我们只需要判断k的一次出现的位置是否存在即可，如果存在，那么我们直接return 5；如果不存在，return 0即可。
*/
class Solution {
public:
    int preimageSizeFZF(int k)
    {
        // 查找一个mid，使得`mid!`中包含的质因子5的个数等于k；
        // `right = 5L * k`作为搜索的上限是合适的，因为只计算了每5个数字出现一个质因子5的情况，没考虑25/125造成的多出的5的情况；
        // 真实的`right!`中包含的质因子5会更多，其结果中的后缀0 >= k；所有`5L * k`作为搜索的上限是合适的。
        long left = 0L, right = 5L * k, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            long n = 5L, count = 0L;

            // 核心要点：用count统计`mid!`中包含的质因子5的个数；
            // n的增长方向是：5 -> 25 -> 125 -> ...
            // 在以数字n进行阶乘的时候，每隔5个数，会出现一次5，每隔25个数，会出现两次5，每隔125次，会出现三次5……，以此类推。
            while (n <= mid) {
                count += mid / n;
                n *= 5;
            }
            if (count < k) {
                left = mid + 1;
            } else if (count > k) {
                right = mid - 1;
            } else { // count == k，找到了。
                return 5;
            }
        }
        // 退出wile循环表示没有找到这样的一个mid，它的阶乘包含的质因子5的个数恰好等于k；
        // 因为后缀0的个数是跳涨的，k不一定存在。
        return 0;
    }
};
