class Solution {
public:
    int rob(vector<int>& nums) {
        std::vector<int> dpVector(nums.size() + 1, std::numeric_limits<int>::min());

        dpVector[0] = 0;
        dpVector[1] = nums[0];
        for (int i = 2; i < dpVector.size(); i++)
            dpVector[i] = std::max(nums[i - 1] + dpVector[i - 2], dpVector[i - 1]);

        return dpVector[nums.size()];
    }
};