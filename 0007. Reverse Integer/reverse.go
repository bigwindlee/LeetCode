package reverse

/* Score: 6.94 :( */
func reverse(x int) int {
  sign := 1
  if x < 0 {
    sign = -1
    x *= -1
  }
  y := 0
  for x > 0 {
    y = y*10 + x%10
    x /= 10
  }
  if y > 0x7FFFFFFF {
    return 0
  }
  return y*sign
}
