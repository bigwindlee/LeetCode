package palindrome

import (
	"testing"
)

func TestIsPalindrome(t *testing.T) {
	testdata := []struct {
		in       int
		expected bool
	}{
		{1000021, false},
		{0, true},
		{9, true},
		{10, false},
		{12321, true},
		{123321, true},
		{12322, false},
		{1001, true},
		{-2147483648, false},
		{-2147447412, false},
		{1111111111111111199, false}, // This number cannot be reversed because of overflow
	}

	for i := range testdata {
		if isPalindrome(testdata[i].in) != testdata[i].expected {
			t.Errorf("%d is palindrome: %v, expected: %v\n",
				testdata[i].in, isPalindrome(testdata[i].in), testdata[i].expected)
		}
	}
}
