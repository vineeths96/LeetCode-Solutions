class Solution {
    std::vector<std::vector<int>> dp;

    int changeRecursive(std::vector<int> coins, int amount, int currentIndex) {
        if (currentIndex == coins.size()) {
            if (amount == 0) return 1;
            else return 0;
        }

        if (dp[currentIndex][amount] != -1)
            return dp[currentIndex][amount];

        int includeCoinWays = 0, excludeCoinWays = 0;

        excludeCoinWays = changeRecursive(coins, amount, currentIndex + 1);
        if (coins[currentIndex] <= amount)
            includeCoinWays = changeRecursive(coins, amount - coins[currentIndex], currentIndex);

        return dp[currentIndex][amount] = includeCoinWays + excludeCoinWays;
    }

public:
    int change(int amount, vector<int>& coins) {
        dp = std::vector<std::vector<int>>(coins.size() + 1, std::vector<int>(amount + 1, -1));
        return changeRecursive(coins, amount, 0);        
    }
};