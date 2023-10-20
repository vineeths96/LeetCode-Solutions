class Solution {
    std::vector<int> dpVector;

    int minCostClimbingStairsRecursive(const std::vector<int> &cost, int currentIndex) {
        if (currentIndex >= static_cast<int>(cost.size()))
            return 0;

        if (dpVector[currentIndex + 1] != -1)
            return dpVector[currentIndex + 1];

        int oneStep = minCostClimbingStairsRecursive(cost, currentIndex + 1);
        int twoStep = minCostClimbingStairsRecursive(cost, currentIndex + 2);

        return dpVector[currentIndex + 1] = std::min(oneStep, twoStep) + (currentIndex == -1 ? 0 : cost[currentIndex]);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        dpVector = std::vector<int>(cost.size() + 1, -1);
        return minCostClimbingStairsRecursive(cost, -1);
    }
};