package ispalindrome

import (
	"testing"
)

func TestIsPalindrome(t *testing.T) {
	testdata := []struct {
		in  string
		out bool
	}{
		{"", true},
		{" ", true},
		{".,", true},
		{"ab", false},
		{"A man, a plan, a canal: Panama", true},
		{"race a car", false},
	}

	for i := range testdata {
		actual := isPalindrome(testdata[i].in)
		expected := testdata[i].out
		if actual != expected {
			t.Errorf("%q, actual: %t, expected: %t\n", testdata[i].in, actual, expected)
		}
	}
}
