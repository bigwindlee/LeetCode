|LeetCode|要点|
|------------------------|------------------------|
|[15. 三数之和][github-leetcode-0015]|先对数组排序，然后固定一个数字，再使用双指针在右边区间寻找两个数，使得它们的和等于目标值。|
|[18. 四数之和][github-leetcode-0018]|先对数组排序，然后通过双循环固定两个数字，再使用双指针在右边区间寻找两个数，使得它们的和等于目标值。|
|[26. 删除有序数组中的重复项][github-leetcode-0026]|双指针：指针`i`指示回填；指针`j`寻找不同于左边的数字，从数组头部依次回填；|
|[71. 简化路径][github-leetcode-0071]|双指针+栈：使用双指针界定由'/'分割的segment；用栈处理两个点 '..' 将目录切换到上一级；|
|[75. 颜色分类][github-leetcode-0075]|一趟扫描，扫描过程中通过通过2个指针p0和p2定位，把0往前搬运，把2往后搬运。；|
|[88. 合并两个有序数组][github-leetcode-0088]|三指针逆向扫描/填充|
|[151. 反转字符串中的单词][github-leetcode-0151]|双指针：right从末尾开始逆向扫描，指向一个单词的末字符；left寻找right所指向单词的左边界；|
|[165. 比较版本号][github-leetcode-0165]|双指针：以点号界定区间并提取数字|
|287. 寻找重复数|环路检测：把数组的`value`作为下一步的`index`，可以把数组串成一个链表。|
|[443. 压缩字符串][github-leetcode-0443]|双指针：left指向一串重复字符的首个字符；right指向下一串重复字符的首个字符；另有w指针，指示待写入的位置；|
|[468. 验证IP地址][github-leetcode-0468]|双指针last/cur：last的初值为-1；cur的终值为queryIP.size()；这样可以对IP地址划分区间；|
|[LCR 181. 字符串中的单词反转][github-leetcode-LCR181]|双指针扫描字符串，并用作界定符；|

# 双指针总结
**双指针**（Two Pointers）是一种常见的算法技巧，它经常用于解决数组或链表相关的问题，尤其是当你需要高效处理部分元素的组合、配对或查找问题时。双指针技巧通过使用两个指针在数据结构（通常是数组或链表）上进行遍历，从而达到减少时间复杂度的目的。

在 LeetCode 上，**双指针** 是一个常见的标签，表示使用双指针技术是解决这类问题的有效方法。

---
### 双指针的类型：

双指针策略可以分为两种常见的类型：

1. **对撞指针**（Two Pointers from Opposite Ends）：
   - 一般用于排序数组或有序数据结构。
   - 两个指针从数组的两端向中间移动，通常用于寻找特定的条件或组合（比如特定的和、区间）。
   - 例子：**两数之和 II**（有序数组）、**三数之和**、**四数之和**等问题。

2. **快慢指针**（Two Pointers with Different Speeds）：
   - 一般用于链表、字符串或序列处理问题。
   - 一个指针（快指针）通常移动更快，另一个指针（慢指针）移动较慢。常用于解决环检测、重复元素查找等问题。
   - 例子：**链表的环检测**、**删除有序链表中的重复项**、**寻找链表的中间节点**等问题。

---
### 双指针的作用：

1. **减少时间复杂度**：
   - 双指针技术通过同时使用两个指针，可以减少问题的时间复杂度。例如，暴力解决四数之和的复杂度是 \(O(n^4)\)，而使用双指针法，可以将其复杂度降为 \(O(n^3)\)。
   
2. **优化空间复杂度**：
   - 通过直接在原数组上操作，可以避免额外的空间开销（如栈或队列），从而优化空间复杂度。

---
### 举例说明：

#### 1. **三数之和**（Three Sum）：
   - 这是一个典型的使用双指针解决的 LeetCode 问题。目标是找到所有不重复的三个数，使它们的和为零。
   - 思路是先对数组排序，然后固定一个数字，再使用双指针在剩余部分寻找两个数，使得它们的和等于目标值。

```cpp
for (int i = 0; i < n - 2; ++i) {
    int left = i + 1, right = n - 1;
    while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
            // 找到一个解
        } else if (sum < 0) {
            ++left;  // 增大 sum
        } else {
            --right; // 减小 sum
        }
    }
}
```

#### 2. **链表中的环检测**（Floyd's Cycle Detection Algorithm / 快慢指针）：
   - 另一个使用双指针的例子是检测链表中的环。一个指针每次前进一步，另一个指针每次前进两步。如果链表中存在环，那么两个指针最终会在环中相遇。
```cpp
ListNode *slow = head, *fast = head;
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
        // 检测到环
    }
}
```   
---
### 总结：
**双指针**是一种强大且常用的算法技巧，它通过同时使用两个指针来高效地遍历数组或链表，解决一些复杂度较高的问题。它不是一个独立的算法，而是一种**策略**，可以在许多算法问题中应用，比如查找和问题、环检测、移动窗口等。


在四数之和的解法中，双指针方法的运用可以极大地减少枚举所有组合所需的时间复杂度，使问题更高效地解决。


[github-leetcode-0015]: ../../0015.%203Sum/0015_threeSum.h
[github-leetcode-0018]: ../../0018.%204Sum/0018_fourSum.h
[github-leetcode-0071]: ../../0071.%20Simplify%20Path/0071_simplifyPath.h
[github-leetcode-0468]: ../../0468.%20Validate%20IP%20Address/0468_validIPAddress.h
[github-leetcode-LCR181]: ../../LCR181.%20Reverse%20Message/LCR181_reverseMessage.h
[github-leetcode-0088]: ../../0088.%20Merge%20Sorted%20Array/0088_merge.h
[github-leetcode-0026]: ../../0026.%20Remove%20Duplicates%20from%20Sorted%20Array/0026_removeDuplicates.h
[github-leetcode-0075]: ../../0075.%20Sort%20Colors/0075_sortColors.h
[github-leetcode-0165]: ../../0165.%20Compare%20Version%20Numbers/0165_compareVersion.h
[github-leetcode-0151]: ../../0151.%20Reverse%20Words%20in%20a%20String/0151_reverseWords.h
[github-leetcode-0443]: ../../0443.%20String%20Compression/0443_compress.h
