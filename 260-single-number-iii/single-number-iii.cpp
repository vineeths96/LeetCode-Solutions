class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long int xorOfNums = 0;
        for (const int &num : nums)
            xorOfNums ^= num;

        long int bitmask = xorOfNums & (-xorOfNums);
        int firstNumber = 0;
        int secondNumber = 0;

        for (const int &num : nums) {
            if (num & bitmask)
                firstNumber ^= num;
            else
                secondNumber ^= num;
        }

        return {firstNumber, secondNumber};
    }
};