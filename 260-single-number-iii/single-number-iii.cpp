class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorOfNums = 0;

        for (const int &num : nums)
            xorOfNums ^= num;

        int rightSetBit = 0;
        while ((xorOfNums & 1 << rightSetBit) == 0)
            rightSetBit++;

        int firstNumber = xorOfNums;
        int secondNumber = xorOfNums;

        for (const int &num : nums) {
            if (num & 1 << rightSetBit)
                firstNumber ^= num;
            else
                secondNumber ^= num;
        }

        return {firstNumber, secondNumber};
    }
};