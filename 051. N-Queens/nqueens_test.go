package nqueens

import (
	"fmt"
	"testing"
)

func TestSolveNQ(t *testing.T) {
	res := solveNQueens(4)
	if len(res) == 0 {
		fmt.Println("Solution does not exist.")
	} else {
		fmt.Printf("\n==== %d solution(s) ====\n\n", len(res))
		for i := range res {
			for j := range res[i] {
				fmt.Printf("%s\n", res[i][j])
			}
			fmt.Println()
		}
	}

}
