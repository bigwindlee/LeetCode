class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r = 0;
        for(int i=0; i<32; i++){
            r = (r<<1) + (n&1);  //先算术运算，后移位运算，最后位运算。
            n >>= 1;
        }
        return r;
    }
};