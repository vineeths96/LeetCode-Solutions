class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t nDash = 0;
        for (int i = 0; i < 32; i++) {
            uint32_t bit = n >> i & 1;
            nDash = nDash | bit << (31 - i);
        }

        return nDash;
    }
};