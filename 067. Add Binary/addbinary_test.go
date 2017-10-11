package addbinary

import (
	"testing"
)

func TestAddBinary(t *testing.T) {
	testdata := []struct {
		a        string
		b        string
		expected string
	}{
		{"11", "1", "100"},
		{"0", "0", "0"},
	}

	for i := range testdata {
		el := testdata[i]
		actual := addBinary(el.a, el.b)
		expected := el.expected

		if actual != expected {
			t.Errorf("a: %q, b: %q, actual: %q, expected: %q\n", el.a, el.b, actual, expected)
		}
	}
}
