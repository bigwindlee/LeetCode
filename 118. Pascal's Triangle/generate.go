package triangle

/*
118. Pascal's Triangle

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

func generate(numRows int) [][]int {
	if numRows == 0 {
		return [][]int{}
	} else if numRows == 1 {
		return [][]int{[]int{1}}
	}

	child := generate(numRows - 1)
	ctail := child[len(child)-1] // child tail
	curr := make([]int, len(ctail)+1)
	curr[0] = 1
	curr[len(ctail)] = 1
	for i := 0; i < len(ctail)-1; i++ {
		curr[i+1] = ctail[i] + ctail[i+1]
	}
	return append(child, curr)
}
