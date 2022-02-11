思路：
  1）brute-force, 使用双重循环；

  2）使用map 寻找 duplicate value；

  3）滑动窗口 和 map 结合使用，删除滑出的元素，添加滑入的元素到 map 中看是否有 duplicate value；
