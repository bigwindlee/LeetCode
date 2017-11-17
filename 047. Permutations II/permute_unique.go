package permute2

func permuteUnique(nums []int) [][]int {
	options := []func(nums []int) [][]int{permuteUnique0}
	return options[0](nums)
}

/*------------------------------------------------------------------------------*/

func permuteUnique0(nums []int) [][]int {
	var res [][]int
	var path []int
	visit := make([]bool, len(nums))
	backtrack0(nums, 0, visit, &path, &res)
	return res
}

func backtrack0(nums []int, depth int, visit []bool, path *[]int, res *[][]int) {
	if depth == len(nums) {
		if !contains(*res, *path) {
			*res = append(*res, intSliceDuplicate(*path))
		}
		return
	}
	for i := 0; i < len(nums); i++ {
		if !visit[i] {
			visit[i] = true
			*path = append(*path, nums[i])
			backtrack0(nums, depth+1, visit, path, res)
			*path = (*path)[:len(*path)-1]
			visit[i] = false
		}
	}
}

func contains(a [][]int, b []int) bool {
	for i := range a {
		if intSliceEqual(a[i], b) {
			return true
		}
	}
	return false
}

func intSliceEqual(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func intSliceDuplicate(a []int) []int {
	if len(a) == 0 {
		return []int{}
	}
	b := make([]int, len(a))
	copy(b, a)
	return b
}
