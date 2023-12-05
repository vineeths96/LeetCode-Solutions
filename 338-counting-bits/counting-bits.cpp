class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> bits;
        for (int i = 0; i <= n; i++) {
            int ones = 0;
            int num = i;
            
            while (num) {
                if (num & 1) ones++;
                num = num >> 1;
            }

            bits.push_back(ones);
        }

        return bits;
    }
};