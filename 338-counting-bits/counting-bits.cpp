class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> bits;
        for (int i = 0; i <= n; i++) {
            int ones = __builtin_popcount(i);
            bits.push_back(ones);
        }

        return bits;
    }
};