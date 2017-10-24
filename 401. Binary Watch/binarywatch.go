package binarywatch

import (
	"fmt"
)

/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.
*/

func readBinaryWatch(num int) []string {
	res := make([]string, 0)
	for i := 0; i < 12; i++ {
		for j := 0; j < 60; j++ {
			if bitCount(i<<6+j) == num {
				res = append(res, fmt.Sprintf("%d:%02d", i, j))
			}
		}
	}
	return res
}

func bitCount(n int) int {
	res := 0
	for n > 0 {
		res += n & 0x1
		n >>= 1
	}
	return res
}
