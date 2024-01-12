class Solution {
    std::vector<std::vector<int>> dp;

    int maxCoinsRecursive(const std::vector<int> &nums, int left, int right) {
        if (left > right)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int maxCoins = 0;
        for (int i = left; i <= right; i++) {
            int coinsExceptI = maxCoinsRecursive(nums, left, i - 1) + maxCoinsRecursive(nums, i + 1, right);
            int burstI = nums[left - 1] * nums[i] * nums[right + 1];
            maxCoins = std::max(maxCoins, coinsExceptI + burstI);
        }

        return dp[left][right] = maxCoins;
    }

public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        dp = std::vector<std::vector<int>>(nums.size(), std::vector<int>(nums.size(), -1));
        return maxCoinsRecursive(nums, 1, nums.size() - 2);
    }
};