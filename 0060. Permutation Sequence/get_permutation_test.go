package getpermute

import (
	"testing"
)

func TestGetPermutation(t *testing.T) {
	testdata := []struct {
		n        int
		k        int
		expected string
	}{
		{3, 1, "123"},
		{3, 3, "213"},
		{3, 6, "321"},
	}

	for i := range testdata {
		el := testdata[i]
		actual := getPermutation(el.n, el.k)
		if actual != el.expected {
			t.Errorf("Case #%d\texpected: %q, actual: %q\n", i, el.expected, actual)
		}
	}
}
