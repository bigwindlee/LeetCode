package reversevow

import (
	"testing"
)

func TestReverseVowels(t *testing.T) {
	testdata := [][2]string{
		{"aA", "Aa"},
		{"hello", "holle"},
		{"leetcode", "leotcede"},
		{"bcd", "bcd"},
		{"a.b,.", "a.b,."},
	}

	for i := range testdata {
		el := &testdata[i]
		actual := reverseVowels(el[0])
		expected := el[1]
		if actual != expected {
			t.Errorf("reverseVowels(%q) get %q, expected: %q\n", el[0], actual, expected)
		}
	}
}
