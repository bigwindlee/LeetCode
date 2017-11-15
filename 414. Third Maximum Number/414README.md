思路：
  1）求数组中第三大的数字，把问题转化为让数组中的数字依次争抢3个席位！

  2）如何标识席位为空是一个难点。如果用int类型表示席位，那么如何标识席位为空呢？用math.MinInt32是不对的，因为有可能恰好有个candidate为math.MinInt32，这样就无法区分席位到底有没有被占用。
  正确的做法是用 * int 表示席位，用 nil 标识席位为空。这样也不必把 candidate 放入到席位中来，而是让席位指向 candidate 。

  3）基于以上思路，算法就比较简单了。数组中的 candidate 依次争抢3个席位（先从大的抢起），如果席位为空，则直接占用，如果已被占用但自己更大，则也占用并把 candidate 向小的席位挤。


  func thirdMax(nums []int) int {
  	var max1, max2, max3 *int
  	for i := 0; i < len(nums); i++ {
  		if equal(nums[i], max1) || equal(nums[i], max2) || equal(nums[i], max3) {
  			continue
  		}
  		if max1 == nil || nums[i] > *max1 {
  			max3 = max2
  			max2 = max1
  			max1 = &nums[i]
  		} else if max2 == nil || nums[i] > *max2 {
  			max3 = max2
  			max2 = &nums[i]
  		} else if max3 == nil || nums[i] > *max3 {
  			max3 = &nums[i]
  		}
  	}

  	if max3 != nil {
  		return *max3
  	}
  	return *max1
  }

  func equal(a int, b *int) bool {
  	return b != nil && *b == a
  }
