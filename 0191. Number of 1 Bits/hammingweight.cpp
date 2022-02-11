/*
The key idea here is to realize that for any number n, doing a bit-wise AND of n and (n-1) flips the least-significant 1-bit in n to 0.
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int r = 0;
        while(n!=0){
            r++;
            n &= (n-1);
        }
        return r;
    }
};