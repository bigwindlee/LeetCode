package wordsearch

import (
	"fmt"
	"testing"
)

func TestExist(t *testing.T) {
	board := make([][]byte, 3)
	board[0] = []byte("ABCE")
	board[1] = []byte("SFCS")
	board[2] = []byte("ADEE")
	fmt.Printf("%v\n", exist(board, "ABCCED"))
	fmt.Printf("%v\n", exist(board, "SEE"))
	fmt.Printf("%v\n", exist(board, "ABCB"))
}

//TODO: Generate maxtix by string!
