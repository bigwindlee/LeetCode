|LeetCode|要点|
|-------------------------------------|-------------------------------------|
|410. 分割数组的最大值|`二分查找`搜索最大子数组和的最小可能值；`贪心算法`验证每次二分查找中间值是否是一个合法的解。|

## 什么是二分查找？

**二分查找**是一种高效的搜索算法，适用于**有序数组或范围**中的查找问题。它通过每次将搜索范围减半来加速查找过程，时间复杂度为 \(O(\log n)\)。二分查找的基本步骤如下：
1. 找到当前范围的中间位置 `mid`。
2. 将目标值与中间值比较：
   - 若相等，查找成功，返回 `mid`。
   - 若目标值小于中间值，则缩小搜索范围到左半部分。
   - 若目标值大于中间值，则缩小搜索范围到右半部分。
3. 重复以上步骤，直到找到目标值或确定目标值不存在。

---

## 二分查找适合解决什么样的问题？

二分查找适合用于解决**有序性**或**单调性**的问题，主要有以下几类：
1. **有序数组中查找特定元素**：通过折半查找加速查找过程。
2. **查找满足某条件的最小/最大值**：适用于查找某个条件下的临界值，如最小化某个最大值。
3. **查找某个值的插入位置**：如有序数组中查找目标值应插入的位置。
4. **在一个有上下界的范围内搜索**：该范围具有单调性，并且可以通过验证中间值来逐步缩小搜索范围。

---

## 使用二分查找的核心要点是什么？

1. **有序性或单调性**：
   - 数据需要是**有序的**，或者问题满足**单调性**（例如随着某个变量的增大或减小，条件逐渐满足或不满足）。
   
2. **定义上下界**：
   - 确定搜索范围 `[low, high]`，并通过不断缩小这个区间来查找目标值。
   
3. **中间值计算**：
   - 中间值通常由 `mid = low + (high - low) / 2` 计算，以避免整数溢出问题。
   
4. **判定条件**：
   - 针对不同问题，设计合适的判定条件，决定是更新左边界还是右边界。
   
5. **收敛条件**：
   - 结束的条件通常是 `low == high` 或者满足某种精度要求时停止。
   - 有些情况下可能需要在退出循环后做一次结果验证。

---

## LeetCode中“二分查找”相关的问题

在 LeetCode 中，以下是一些典型的与二分查找相关的问题：

1. [LeetCode 704: 二分查找 (Binary Search)](https://leetcode-cn.com/problems/binary-search/)
   - 经典的二分查找问题，查找有序数组中的目标值。

2. [LeetCode 33: 搜索旋转排序数组 (Search in Rotated Sorted Array)](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)
   - 在旋转后的有序数组中查找目标值。

3. [LeetCode 34: 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
   - 在有序数组中查找目标值的起始和结束位置。

4. [LeetCode 69: x 的平方根 (Sqrt(x))](https://leetcode-cn.com/problems/sqrtx/)
   - 使用二分查找求解平方根。

5. [LeetCode 153: 寻找旋转排序数组中的最小值 (Find Minimum in Rotated Sorted Array)](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)
   - 在旋转的有序数组中查找最小值。

6. [LeetCode 374: 猜数字大小 (Guess Number Higher or Lower)](https://leetcode-cn.com/problems/guess-number-higher-or-lower/)
   - 在一个范围内猜数字，可以使用二分查找。

7. [LeetCode 875: 爱吃香蕉的珂珂 (Koko Eating Bananas)](https://leetcode-cn.com/problems/koko-eating-bananas/)
   - 通过二分查找计算最小的吃香蕉速度。

8. [LeetCode 410: 分割数组的最大值 (Split Array Largest Sum)](https://leetcode-cn.com/problems/split-array-largest-sum/)
   - 使用二分查找解决分割数组问题。

9. [LeetCode 1011: 在 D 天内送达包裹的能力 (Capacity To Ship Packages Within D Days)](https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/)
   - 二分查找包裹的最小运送能力。

10. [LeetCode 162: 寻找峰值 (Find Peak Element)](https://leetcode-cn.com/problems/find-peak-element/)
    - 二分查找数组中的峰值元素。

---

通过掌握二分查找的基础和核心要点，可以更好地应对各种相关的算法问题。
