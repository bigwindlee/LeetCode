思路：
  1）回溯法的本质是二维展开；回溯法的核心是确定2个维度分别是什么；

  2）就本题而言，第1个维度是从candidates中任取一个数的变化范围（可以是candidates中的任何一个），使用for循环遍历第1个维度；
     第2个维度depth如何确定？用comb中的和sum来确定；当sum == target时，depth到底了，找到一个解；当sum > target时，depth也到底了，但是不是解；

  3）combinationSum_1()相对于combinationSum_0()的改进点在于：不必经常性的计算comb中数字的和，而是通过target-v递归参数传递下去，减到0就表示找到一个解了！
