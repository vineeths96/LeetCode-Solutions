class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> uglyNums{1}; 
        int two = 0, three = 0, five = 0;

        for (int i = 1; i < n; i++) {
            int num = std::min(uglyNums[two] * 2, std::min(uglyNums[three] * 3, uglyNums[five] * 5));

            uglyNums.push_back(num);

            if (num == uglyNums[two] * 2) two++;
            if (num == uglyNums[three] * 3) three++;
            if (num == uglyNums[five] * 5) five++;
        }

        return uglyNums[n - 1];
    }
};