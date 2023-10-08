class Solution {
    std::vector<std::vector<int>> dpVector;

    int coinChangeRecursive(const std::vector<int> &coins, int amount, int currentIndex) {
        if (currentIndex == coins.size()) {
            if (amount == 0) return 0;
            else return std::numeric_limits<int>::max();
        }

        if (dpVector[currentIndex][amount] != -1)
            return dpVector[currentIndex][amount];

        int includeCount = std::numeric_limits<int>::max(), excludeCount = std::numeric_limits<int>::max();
        excludeCount = coinChangeRecursive(coins, amount, currentIndex + 1);
        if (coins[currentIndex] <= amount) {
            includeCount = coinChangeRecursive(coins, amount - coins[currentIndex], currentIndex);
            if (includeCount != std::numeric_limits<int>::max()) includeCount += 1;
        }
        
        return dpVector[currentIndex][amount] = std::min(includeCount, excludeCount);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        dpVector = std::vector<std::vector<int>>(coins.size() + 1, std::vector<int>(amount + 1, -1));
        int minCoins = coinChangeRecursive(coins, amount, 0);
        return minCoins == std::numeric_limits<int>::max() ? -1 : minCoins;
    }
};