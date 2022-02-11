package ishappy

import (
	"testing"
)

func TestIsHappy(t *testing.T) {
	testdata := []struct {
		n        int
		expected bool
	}{
		{19, true},
		{18, false},
		{13, true},
		{39, false},
		{7, true},
	}

	for i := range testdata {
		if isHappy(testdata[i].n) != testdata[i].expected {
			t.Errorf("%d is happy? %v, expected: %v\n",
				testdata[i].n,
				isHappy(testdata[i].n),
				testdata[i].expected)
		}
	}
}
