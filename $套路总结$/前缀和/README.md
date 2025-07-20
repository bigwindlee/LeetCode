|LeetCode|Description|
|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------|
|[238. 除自身以外数组的乘积][github-leetcode-0238]|前缀积 * 后缀积|
|[548. 将数组分割成和相等的子数组][github-leetcode-0548] |找到三个分割点 (i, j, k)，把数组砍成四截，固定住j值，然后双指针i/k分别在2段内扫描；|
|[724. 寻找数组的中心下标][github-leetcode-0724]|前缀和：中心下标`i`满足：2 * pre_sum + nums[i] = sum|
|[1310. 子数组异或查询](https://github.com/bigwindlee/LeetCode/blob/master/1310.%20XOR%20Queries%20of%20a%20Subarray/1310_xorQueries.h) | 前缀异或（前缀和的思想推广到异或操作） |
|[1983. 范围和相等的最宽索引对][github-leetcode-1983]|2个数组差值的前缀和；|
|LCR 012. 寻找数组的中心下标|前缀和：同[724][github-leetcode-0724]|

### 什么是前缀和？

前缀和是一种对数组元素进行累加的技巧。具体来说，给定一个数组 `arr`，它的前缀和数组 `prefixSum` 是通过依次累加数组中的元素形成的。例如：

对于数组 `arr = [a1, a2, a3, ..., an]`，前缀和数组 `prefixSum` 是这样计算的：

- `prefixSum[0] = arr[0]`
- `prefixSum[1] = arr[0] + arr[1]`
- `prefixSum[2] = arr[0] + arr[1] + arr[2]`
- ...
- `prefixSum[i] = arr[0] + arr[1] + ... + arr[i]`

### 前缀和的公式：

我们可以使用下面的递推公式来表示前缀和：

- `prefixSum[0] = arr[0]`
- `prefixSum[i] = prefixSum[i-1] + arr[i]` （对于 i > 0）

### 前缀和的主要应用场景：

前缀和特别适合解决**区间求和**和**快速查询**相关的问题。通过提前计算出数组的前缀和，我们可以在常数时间内（O(1)）求出任意一个子数组的和。这是因为，利用前缀和，我们可以轻松地通过如下公式来计算区间 `[L, R]` 的和：

- 区间 `[L, R]` 的和：`sum(L, R) = prefixSum[R] - prefixSum[L-1]`（当 `L > 0` 时）
- 如果 `L = 0`，则 `sum(0, R) = prefixSum[R]`

### 前缀和适合解决的问题类型：

1. **区间求和问题**：
    - 如果有多个区间查询，询问子数组 `[L, R]` 的和，通过提前构建前缀和数组可以将每次查询的复杂度从 O(n) 降低到 O(1)。
    
    例如： 给定一个数组 `arr = [1, 2, 3, 4, 5]` 和查询 `(L, R) = (1, 3)`，使用前缀和可以直接计算区间和为 `prefixSum[3] - prefixSum[0] = 9`。

2. **子数组的某种属性问题**：
    - 除了求和之外，前缀和还可以用于求解子数组的其他属性，比如在某些算法中前缀和可以用来计算子数组的异或值（如之前提到的异或查询），或是用于判断连续子数组的特性。

3. **处理动态数组更新**：
    - 在某些动态更新操作中，前缀和可以帮助快速查询更新后的区间和。不过，前缀和在处理**多次数组元素更新**的场景下不如树状数组或线段树高效，因为前缀和本质上是静态数组的查询技巧。

4. **频率统计与计数问题**：
    - 在某些问题中，前缀和也可以用于统计某个值在数组中的出现次数。例如，在二进制计数问题中，前缀和可以用于计算某些位出现次数的累积和。

### 示例代码：
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    vector<int> prefixSum(n, 0);
    
    // 计算前缀和数组
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    // 查询区间 [1, 3] 的和
    int L = 1, R = 3;
    int result = prefixSum[R] - (L > 0 ? prefixSum[L - 1] : 0);
    cout << "Sum of subarray [1, 3] is: " << result << endl;
    
    return 0;
}
```

[github-leetcode-0548]: ../../0548.%20Split%20Array%20with%20Equal%20Sum/0548_splitArray.h
[github-leetcode-0724]: ../../0724.%20Find%20Pivot%20Index/0724_pivotIndex.h
[github-leetcode-1983]: ../../1983.%20Widest%20Pair%20of%20Indices/1983_widestPairOfIndices.h
[github-leetcode-0238]: ../../0238.%20Product%20of%20Array%20Except%20Self/0238_productExceptSelf.h
