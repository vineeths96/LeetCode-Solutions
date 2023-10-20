class Solution {
public:
    int jump(vector<int>& nums) {
        std::vector<int> dpVector(nums.size(), std::numeric_limits<int>::max());
        dpVector.back() = 0;

        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int step = 1; step <= nums[i]; step++) {
                if (i + step < nums.size() && dpVector[i + step] != std::numeric_limits<int>::max())
                    dpVector[i] = std::min(dpVector[i], 1 + dpVector[i + step]);
            }
        }

        return dpVector[0];
    }
};