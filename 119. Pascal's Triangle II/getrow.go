package triangle2

/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

func getRow(rowIndex int) []int {
	if rowIndex == 0 {
		return []int{1}
	}

	prev := getRow(rowIndex - 1)
	res := make([]int, len(prev)+1)
	res[0], res[len(prev)] = 1, 1
	for i := 0; i < len(prev)-1; i++ {
		res[i+1] = prev[i] + prev[i+1]
	}
	return res
}
