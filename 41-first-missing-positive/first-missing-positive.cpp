class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int targetPostiveNumber = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0)
                continue;

            if (nums[i] == targetPostiveNumber) {
                targetPostiveNumber++;

                while (i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
            }
            else
                break;
        }

        return targetPostiveNumber;
    }
};