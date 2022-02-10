package maxarea

import (
	. "leetcomm"
)

func maxAreaOfIsland(grid [][]int) int {
	x := len(grid)
	if x == 0 {
		return 0
	}
	y := len(grid[0])
	if y == 0 {
		return 0
	}
	max := 0
	visit := make([][]int, x)
	for i := 0; i < x; i++ {
		visit[i] = make([]int, y)
	}

	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			if grid[i][j] == 1 && visit[i][j] == 0 {
				max = Max(max, getArea(grid, visit, i, j, x, y))
			}
		}
	}

	return max
}

func getArea(grid, visit [][]int, i, j, x, y int) int {
	if i < 0 || i >= x || j < 0 || j >= y || grid[i][j] == 0 || visit[i][j] == 1 {
		return 0
	}
	visit[i][j] = 1
	return 1 + getArea(grid, visit, i-1, j, x, y) + getArea(grid, visit, i+1, j, x, y) + getArea(grid, visit, i, j-1, x, y) + getArea(grid, visit, i, j+1, x, y)
}
