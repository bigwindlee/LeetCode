package countsay

import (
	"testing"
)

func TestCountAndSay(t *testing.T) {
	testdata := []struct {
		in  int
		out string
	}{
		{1, "1"},
		{2, "11"},
		{3, "21"},
		{4, "1211"},
		{5, "111221"},
	}

	for i := range testdata {
		actual := countAndSay(testdata[i].in)
		expected := testdata[i].out
		if actual != expected {
			t.Errorf("countAndSay(%d) is %q, expected: %q\n", testdata[i].in, actual, expected)
		}
	}
}

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
