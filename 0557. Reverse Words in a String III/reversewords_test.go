package reversewords

import (
	"testing"
)

func TestReverseWords(t *testing.T) {
	testdata := [][2]string{
		{"", ""},
		{"abc", "cba"},
		{"abc def", "cba fed"},
		{"Let's take LeetCode contest", "s'teL ekat edoCteeL tsetnoc"},
	}

	for i := range testdata {
		actual := reverseWords(testdata[i][0])
		expected := testdata[i][1]

		if actual != expected {
			t.Errorf("reverseWords(%q) get %q, expected: %q\n", testdata[i][0], actual, expected)
		}
	}
}
