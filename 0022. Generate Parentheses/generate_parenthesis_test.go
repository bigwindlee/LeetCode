package generate022

import (
	"fmt"
	"testing"
)

func TestGenerateParenthesis(t *testing.T) {
	testdata := []struct {
		n        int
		expected []string
	}{
		{3, []string{
			"((()))",
			"(()())",
			"(())()",
			"()(())",
			"()()()"}},
	}

	_ = testdata
	fmt.Printf("%v\n", generateParenthesis(3))
}
