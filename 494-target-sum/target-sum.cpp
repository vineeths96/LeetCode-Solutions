class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        std::vector<std::vector<int>> dpVector(nums.size() + 1, std::vector<int>(2 * totalSum + 1, 0));

        dpVector[0][totalSum] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = -totalSum; j <= totalSum; j++) {
                if (dpVector[i - 1][j + totalSum] <= 0) continue;

                dpVector[i][j + nums[i - 1] + totalSum] += dpVector[i - 1][j + totalSum];
                dpVector[i][j - nums[i - 1] + totalSum] += dpVector[i - 1][j + totalSum];
            }
        }

        return std::abs(target) > totalSum ? 0 : dpVector[nums.size()][target + totalSum];
    }
};