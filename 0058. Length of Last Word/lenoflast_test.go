package lenoflast

import (
	"testing"
)

func TestLengthOfLastWord(t *testing.T) {
	testdata := []struct {
		in     string
		expect int
	}{
		{"", 0},
		{"a", 1},
		{"a ", 1},
		{"abc def", 3},
		{"abc", 3},
	}

	for i := range testdata {
		el := testdata[i]
		actual := lengthOfLastWord(el.in)
		expect := el.expect

		if actual != expect {
			t.Errorf("in: %q, out: %d, expect: %d\n", el.in, actual, expect)
		}
	}
}
