package isAnagram

import (
	"testing"
)

func TestIsAnagram(t *testing.T) {
	testdata := []struct {
		s        string
		t        string
		expected bool
	}{
		{"", "", true},
		{"xaaddy", "xbbccy", false}, // break through sum
		{"anagram", "nagaram", true},
		{"a中nagra国m", "naga中国ram", true}, // test unicode
		{"hqbqo", "lsnma", false},        // break through sum-of-squares
		{"vbnxkji", "wqdtegp", false},    // break through sum-of-cubes
	}

	for i := range testdata {
		actual := isAnagram(testdata[i].s, testdata[i].t)
		if actual != testdata[i].expected {
			t.Errorf("%q and %q is anagram: %v, expected: %v\n",
				testdata[i].s, testdata[i].t, actual, testdata[i].expected)
		}
	}
}
