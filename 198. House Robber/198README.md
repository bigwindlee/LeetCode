思路：
  从一个整数数组挑出不相邻的数，使其和最大。
  要求不相邻，则分别在偶数下标和奇数下标分别统计最大和，每次统计还能及时合并上一次统计的结果，算法实现的比较巧妙。

* 1）Linear recursive solution
  56 / 69 test cases passed.
  Status: Time Limit Exceeded

  func rob(nums []int) int {
    l := len(nums)
    if l == 0 {
      return 0
    } else if l == 1 {
      return nums[0]
    } else if l == 2 {
      return max(nums[0], nums[1])
    } else {
      return max(nums[l-1]+rob(nums[:l-2]), rob(nums[:l-1]))
    }
  }


* 2）Non recursive solution
func rob(nums []int) int {
	var a, b int
	for i, v := range nums {
		if i%2 == 0 {
			a = max(a+v, b)
		} else {
			b = max(b+v, a)
		}
	}
	return max(a, b)
}
