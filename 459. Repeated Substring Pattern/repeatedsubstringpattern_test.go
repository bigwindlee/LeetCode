package repeatedsubstringpattern

import (
	"testing"
)

func TestRepeatedSubstringPattern(t *testing.T) {
	testdata := []struct {
		in  string
		out bool
	}{
		{"abab", true},
		{"aa", true},
		{"abcabcabc", true},
		{"abac", false},
		{"a", false},
		{"ab", false},
	}

	for i := range testdata {
		el := testdata[i]
		actual := repeatedSubstringPattern(el.in)
		expected := el.out
		if actual != expected {
			t.Errorf("in: %q, actual: %t, expected: %t\n", el.in, actual, expected)
		}
	}
}
