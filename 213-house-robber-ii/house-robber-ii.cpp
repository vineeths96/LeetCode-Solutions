class Solution {
    int robHouses(const std::vector<int> &nums, int start, int end) {
        int twoStep = 0;
        int oneStep = 0;
        for (int i = start; i <= end; i++) {
            int holder = oneStep;
            oneStep = std::max(nums[i] + twoStep, oneStep);
            twoStep = holder;
        }

        return oneStep;
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