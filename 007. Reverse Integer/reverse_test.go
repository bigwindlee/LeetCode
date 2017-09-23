package reverse

import (
  "testing"
)

func TestReverse(t *testing.T){
  testdata := [][2]int {
    {123, 321},    // {parameter, expected result}
    {-123, -321},
    {100, 1},
    {-100, -1},
  }

  for i := range testdata {
    if reverse(testdata[i][0]) != testdata[i][1] {
      t.Errorf("reverse(%d) = %d, expected: %d",
          testdata[i][0], reverse(testdata[i][0]), testdata[i][1])
    }
  }
}
