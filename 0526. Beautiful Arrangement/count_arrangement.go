package countarrange

func countArrangement(N int) int {
	options := []func(N int) int{countArrangement1}
	return options[0](N)
}

/*------------------------------------------------------------------------------*/
/* 156 ms */
func countArrangement1(N int) int {
	if N == 0 {
		return 0
	}
	visit := make([]bool, N+1)
	return backtrack1(N, visit, 1)
}

func backtrack1(N int, visit []bool, depth int) int {
	if N < depth {
		return 1
	}
	cnt := 0
	for i := 1; i <= N; i++ {
		if !visit[i] && (i%depth == 0 || depth%i == 0) {
			visit[i] = true
			cnt += backtrack1(N, visit, depth+1)
			visit[i] = false
		}
	}
	return cnt
}

/*------------------------------------------------------------------------------*/
/* Returns all the solutions, rather than counting the number of solutions. So it's relatively slow. */
/* 725 ms */
func countArrangement0(N int) [][]int {
	nums := make([]int, N)
	visit := make([]bool, N)
	var path []int
	var res [][]int

	for i := range nums {
		nums[i] = i + 1
	}
	backtrack0(nums, visit, &path, &res)
	return res
}

func backtrack0(nums []int, visit []bool, path *[]int, res *[][]int) {
	for i, v := range *path {
		if (i+1 > v && (i+1)%v != 0) || (i+1 < v && v%(i+1) != 0) {
			return
		}
	}
	if len(nums) == len(*path) {
		tmp := make([]int, len(*path))
		copy(tmp, *path)
		*res = append(*res, tmp)
		return
	}
	for i, v := range nums {
		if !visit[i] {
			visit[i] = true
			*path = append(*path, v)
			backtrack0(nums, visit, path, res)
			*path = (*path)[:len(*path)-1]
			visit[i] = false
		}
	}
}
