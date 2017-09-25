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
		{"xaaddy", "xbbccy", false},
		{"anagram", "nagaram", true},
		{"hqbqo", "lsnma", false},
	}

	for i := range testdata {
		actual := isAnagram(testdata[i].s, testdata[i].t)
		if actual != testdata[i].expected {
			t.Errorf("%q and %q is anagram: %v, expected: %v\n",
				testdata[i].s, testdata[i].t, actual, testdata[i].expected)
		}
	}
}
