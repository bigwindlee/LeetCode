package isvalid

import (
	"testing"
)

func TestIsValid(t *testing.T) {
	testdata := []struct {
		in  string
		out bool
	}{
		{"()", true},
		{"(}", false},
		{"{[]}", true},
		{"()[]{}", true},
		{"{[({()})]}", true},
		{"{[({()})]})", false},
	}

	for i := range testdata {
		actual := isValid(testdata[i].in)
		expected := testdata[i].out
		if actual != expected {
			t.Errorf("in: %q, actual: %t, expected: %t\n", testdata[i].in, actual, expected)
		}
	}
}
