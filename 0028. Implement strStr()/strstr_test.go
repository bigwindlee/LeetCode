package strstr

import (
	// "fmt"
	"testing"
)

func TestStrStr(t *testing.T) {
	testdata := []struct {
		haystack string
		needle   string
		out      int
	}{
		{"abcdef", "bcd", 1},
		{"abcdef", "bcz", -1},
		{"abcdef", "def", 3},
		{"", "abc", -1},
		{"ab", "abc", -1},
	}

	for i := range testdata {
		el := testdata[i]
		actual := strStr(el.haystack, el.needle)
		expected := el.out
		if actual != expected {
			t.Errorf("haystack: %q, needle: %q, actual: %d, expected: %d\n",
				el.haystack, el.needle, actual, expected)
		}
	}
}
