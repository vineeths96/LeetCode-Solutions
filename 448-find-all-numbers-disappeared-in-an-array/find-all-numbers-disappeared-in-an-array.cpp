class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index = 0;

        while (index < nums.size()) {
            if (nums[index] != nums[nums[index] - 1])
                std::swap(nums[index], nums[nums[index] - 1]);
            else
                index++;
        }

        std::vector<int> missingNumbers;
        for (int expectedNumber = 1; expectedNumber <= nums.size(); expectedNumber++) {
            if (nums[expectedNumber - 1] != expectedNumber)
                missingNumbers.push_back(expectedNumber);
        }

        return missingNumbers;
    }
};