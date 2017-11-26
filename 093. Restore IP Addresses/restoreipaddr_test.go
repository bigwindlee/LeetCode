package restoreip

import (
	"fmt"
	"testing"
)

func TestRestoreIpAddresses(t *testing.T) {
	fmt.Printf("%v\n", restoreIpAddresses("25525511135"))
	fmt.Printf("%v\n", restoreIpAddresses("010010"))
}
