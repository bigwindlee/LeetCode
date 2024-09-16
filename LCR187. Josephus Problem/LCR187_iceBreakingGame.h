#pragma once

/*
LCR 187. 破冰游戏
社团共有 num 位成员参与破冰游戏，编号为 0 ~ num-1。成员们按照编号顺序围绕圆桌而坐。社长抽取一个数字 target，从 0 号成员起开始计数，排在第 target 位的成员离开圆桌，且成员离开后从下一个成员开始计数。请返回游戏结束时最后一位成员的编号。
*/

/*
思路分析：
  经典约瑟夫环（Josephus）问题
*/
class Solution {
public:
    int iceBreakingGame(int num, int target)
    {
        int ans = 0;
        for (int i = 2; i <= num; ++i)
            ans = (ans + target) % i;
        return ans;
    }
};