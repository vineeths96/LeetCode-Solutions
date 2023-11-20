class Solution {
    int robHouses(const std::vector<int> &nums, int start, int end) {
        std::vector<int> dpVector(nums.size() + 1, 0);

        dpVector[0] = 0;
        dpVector[1] = nums[start];
        for (int i = 2; i <= end - start + 1; i++)
            dpVector[i] = std::max(nums[start + i - 1] + dpVector[i - 2], dpVector[i - 1]);

        return dpVector[end - start + 1];
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        
        return std::max(robHouses(nums, 0, nums.size() - 2), robHouses(nums, 1, nums.size() - 1)); 
    }
};