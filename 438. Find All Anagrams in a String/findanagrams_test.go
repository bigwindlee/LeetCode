package findanagrams

import (
	"testing"
)

func TestFindAnagrams(t *testing.T) {
	testdata := []struct {
		s        string
		p        string
		expected []int
	}{
		{"cbaebabacd", "abc", []int{0, 6}},
		{"abab", "ab", []int{0, 1, 2}},
		{"aaaaaaaaaa", "aaaaaaaaaaaaa", nil},
	}

	for i := range testdata {
		actual := findAnagrams(testdata[i].s, testdata[i].p)
		if actual == nil && testdata[i].expected == nil {
			return
		}
		if len(actual) == len(testdata[i].expected) {
			for j := range actual {
				if actual[j] != testdata[i].expected[j] {
					t.Errorf("s: %v, p: %v, actual: %v, expected: %v\n",
						testdata[i].s, testdata[i].p, actual, testdata[i].expected)
				}
			}
		} else {
			t.Errorf("s: %v, p: %v, actual: %v, expected: %v\n",
				testdata[i].s, testdata[i].p, actual, testdata[i].expected)
		}
	}
}
