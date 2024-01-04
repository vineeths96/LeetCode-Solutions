class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorVal = x ^ y;

        int weight = 0;
        while (xorVal) {
            weight++;
            xorVal = xorVal & (xorVal - 1);
        }

        return weight;
    }
};