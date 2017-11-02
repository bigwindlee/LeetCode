package merge

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one
sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n)
to hold additional elements from nums2. The number of elements initialized in
nums1 and nums2 are m and n respectively.
*/

func merge(nums1 []int, m int, nums2 []int, n int) {
	res := nums1[:m+n]
	i, j := m-1, n-1
	for k := m + n - 1; k >= 0; k-- {
		if i < 0 {
			copy(res[:j+1], nums2[:j+1])
			break
		} else if j < 0 {
			break
		} else if nums1[i] > nums2[j] {
			res[k] = nums1[i]
			i--
		} else {
			res[k] = nums2[j]
			j--
		}
	}
}
