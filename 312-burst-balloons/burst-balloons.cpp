class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(nums.size(), 0));
        for (int left = dp.size() - 2; left > 0; left--) {
            for (int right = left; right < dp[0].size() - 1; right++) {
                int maxCoins = 0;
                for (int i = left; i <= right; i++) {
                    int exceptI = dp[left][i - 1] + dp[i + 1][right];
                    int burstI = nums[left - 1] * nums[i] * nums[right + 1];

                    maxCoins = std::max(maxCoins, exceptI + burstI);
                }

                dp[left][right] = maxCoins;
            }
        }

        return dp[1][dp.size() - 2];
    }
};