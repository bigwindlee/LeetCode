package letterscombine

import (
	"sort"
	"testing"
)

func TestLetterCombinations(t *testing.T) {
	testdata := []struct {
		digits   string
		expected []string
	}{
		{"", []string{}},
		{"2", []string{"a", "b", "c"}},
		{"23", []string{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
	}

	for i := range testdata {
		el := testdata[i]
		actual := letterCombinations(el.digits)
		if !StringSliceEqual(actual, el.expected) {
			t.Errorf("Case #%d\tactual: %v, expected: %v\n", i, actual, el.expected)
		}
	}

}

func StringSliceEqual(a, b []string) bool {
	if len(a) != len(b) {
		return false
	}
	sort.StringSlice(a).Sort()
	sort.StringSlice(b).Sort()
	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
