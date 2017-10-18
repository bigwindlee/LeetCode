思路：
  1）关于频率的统计，常规解法是使用一个map，被统计的对象作为key；

  2）本题统计票数过半的candidate，有一个著名的算法：
  Boyer-Moore Majority Vote Algorithm
  http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
  其思路是，遍历数组，每个candidate遇到自己的票+1，遇到别人的票-1；减到0立刻更换candidate重新开始统计。基于的事实是，得票没过半的candidate一定会减到0（异己数量更多），幸存下来的一定是得票过半的candidate！
