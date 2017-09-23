package palindrome

import (
	"testing"
)

func TestIsPalindrome(t *testing.T) {
	testdata := []struct {
		in       int
		expected bool
	}{
		{12321, true},
		{123321, true},
		{12322, false},
		{1111111111111111199, false}, // This number cannot be reversed because of overflow
	}

	for i := range testdata {
		if isPalindrome(testdata[i].in) != testdata[i].expected {
			t.Errorf("%d is palindrome: %v, expected: %v\n",
				testdata[i].in, isPalindrome(testdata[i].in), testdata[i].expected)
		}
	}
}
