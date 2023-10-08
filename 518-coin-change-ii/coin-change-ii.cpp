class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<std::vector<int>> dpVector(2, std::vector<int>(amount + 1, 0));

        for (int i = 0; i < dpVector.size(); i++)
            dpVector[i][0] = 1;

        for (int i = 1; i <= coins.size(); i++)
            for (int a = 1; a <= amount; a++)
                dpVector[i % 2][a] = dpVector[(i - 1) % 2][a] + (coins[i - 1] <= a ? dpVector[i % 2][a - coins[i - 1]] : 0);

        return dpVector[coins.size() % 2][amount];
    }
};