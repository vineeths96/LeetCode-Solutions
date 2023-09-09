class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int missingNumber = 0;

        for (const int &num : nums)
            missingNumber ^= num;

        return missingNumber;
    }
};