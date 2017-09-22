package lengthoflongestsubstring

import (
	"testing"
)

func TestLengthOfLongestSubstring(t *testing.T) {
	testdata := []struct {
		len int
		s   string
	}{
		{3, "abcabcbb"},
		{1, "bbbbb"},
		{3, "pwwkew"},
		{4, "zababcda"},
	}

	for i := range testdata {
		if lengthOfLongestSubstring(testdata[i].s) != testdata[i].len {
			t.Errorf("%q sublen: %d expected: %d",
				testdata[i].s,
				lengthOfLongestSubstring(testdata[i].s),
				testdata[i].len)
		}
	}

}
