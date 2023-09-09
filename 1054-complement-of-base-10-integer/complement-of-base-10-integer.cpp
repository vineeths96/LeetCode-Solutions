class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
            
        int nCopy = n;
        int index = 0;
        while (nCopy) {
            n = n ^ (1 << index);
            index++;
            nCopy = nCopy >> 1;
        }

        return n;
    }
};