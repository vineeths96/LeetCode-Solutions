class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<std::vector<int>> dpVector(coins.size() + 1, std::vector<int>(amount + 1, std::numeric_limits<int>::max()));

        for (int i = 0; i < dpVector.size(); i++)
            dpVector[i][0] = 0;

        for (int i = 1; i < dpVector.size(); i++) {
            for (int a = 1; a < dpVector[0].size(); a++) {
                int excludeCount = dpVector[i - 1][a];
                int includeCount = std::numeric_limits<int>::max();
                if (coins[i - 1] <= a && dpVector[i][a - coins[i -1]] != std::numeric_limits<int>::max())
                    includeCount = 1 + dpVector[i][a - coins[i -1]];

                dpVector[i][a] = std::min(includeCount, excludeCount);
            }
        }

        return dpVector[coins.size()][amount] == std::numeric_limits<int>::max() ? -1 : dpVector[coins.size()][amount];
    }
};