思路：
  1）典型的数组内滑动窗口题。使用双重的for循环：外层for循环使窗口滑动，内层for循环求当前窗口内的sum；

  2）滑动窗口在滑动时，窗口内sum的变化是一进一出（一加一减），这样避免双重的for循环，增加时间复杂度。