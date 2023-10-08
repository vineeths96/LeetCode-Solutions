class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<int> dpVector(amount + 1, 0);

        dpVector[0] = 1;

        for (int i = 1; i <= coins.size(); i++)
            for (int a = 0; a <= amount; a++)
                dpVector[a] = dpVector[a] + (coins[i - 1] <= a ? dpVector[a - coins[i - 1]] : 0);

        return dpVector[amount];
    }
};