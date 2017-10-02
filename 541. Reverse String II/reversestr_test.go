package reversestr

import (
	"testing"
)

func TestReverseStr(t *testing.T) {
	testdata := []struct {
		in  string
		k   int
		out string
	}{
		{"abcdefg", 2, "bacdfeg"},
		{"a", 1, "a"},
	}

	for i := range testdata {
		el := &testdata[i]
		actual := reverseStr(el.in, el.k)
		expected := el.out
		if actual != expected {
			t.Errorf("in: %q, k: %d, actual: %q, expected: %q\n", el.in, el.k, actual, expected)
		}
	}
}
