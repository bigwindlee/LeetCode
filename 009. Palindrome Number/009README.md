思路：
    倒置一半，并与剩下的前一半进行比较。
    
误区：
    1）先转成字符串。
        不可以，因为有不使用额外空间的限制。
    2）倒置后判断相等。
        不可以，倒置后的数可能overflow。
    3）每次提取头尾两个数字，判断它们是否相等，判断后去掉头尾两个数字。
        不可以，无法处理中间数字为0的数，比如100001。
    
Time complexity : We divided the input by 10 for every iteration.
Space complexity : O(1).

