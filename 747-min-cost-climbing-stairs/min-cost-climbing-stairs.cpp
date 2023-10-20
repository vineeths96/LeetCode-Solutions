class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> dpVector(cost.size() + 1, 0);

        for (int i = 2; i < dpVector.size(); i++)
            dpVector[i] = std::min(cost[i - 1] + dpVector[i - 1], cost[i - 2] + dpVector[i - 2]);

        return dpVector[cost.size()];
    }
};