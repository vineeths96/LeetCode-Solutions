class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<std::vector<int>> dpVector(coins.size() + 1, std::vector<int>(amount + 1, 0));

        for (int i = 0; i < dpVector.size(); i++)
            dpVector[i][0] = 1;

        for (int i = 1; i < dpVector.size(); i++)
            for (int a = 1; a < dpVector[0].size(); a++)
                dpVector[i][a] = dpVector[i - 1][a] + (coins[i - 1] <= a ? dpVector[i][a - coins[i - 1]] : 0);

        return dpVector[coins.size()][amount];
    }
};