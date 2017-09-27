package minwindow

import (
	"testing"
)

func TestMinWindow(t *testing.T) {
	testdata := []struct {
		s        string
		t        string
		expected string
	}{
		{"ADOBECODEBANC", "ABC", "BANC"},
		{"ADOBECODEBANC", "XYZ", ""},
		{"", "", ""},
	}

	for i := range testdata {
		actual := minWindow(testdata[i].s, testdata[i].t)
		if actual != testdata[i].expected {
			t.Errorf("s: %q, t:%q, actual:%q, expected: %q\n",
				testdata[i].s, testdata[i].t, actual, testdata[i].expected)
		}
	}
}
