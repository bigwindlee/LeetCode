package wordsearch

var next_x = []int{0, 0, -1, 1}
var next_y = []int{-1, 1, 0, 0}

func exist(board [][]byte, word string) bool {
	if len(word) == 0 {
		return true
	}
	if len(board) == 0 {
		return false
	}
	visit := make([][]bool, len(board))
	for i := 0; i < len(board); i++ {
		visit[i] = make([]bool, len(board[0]))
	}

	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[i]); j++ {
			if board[i][j] == word[0] {
				if backtrack(board, visit, i, j, word, 0) {
					return true
				}
			}
		}
	}
	return false
}

func backtrack(board [][]byte, visit [][]bool, row, col int, word string, depth int) bool {
	if depth == len(word) {
		return true
	}
	if !isValid(board, row, col) {
		return false
	}
	for i := 0; i < len(next_x); i++ {
		if !visit[row][col] && board[row][col] == word[depth] {
			visit[row][col] = true
			if backtrack(board, visit, row+next_x[i], col+next_y[i], word, depth+1) {
				return true
			}
			visit[row][col] = false
		}
	}
	return false
}

func isValid(board [][]byte, row, col int) bool {
	if row < 0 || row >= len(board) {
		return false
	}
	if col < 0 || col >= len(board[0]) {
		return false
	}
	return true
}
