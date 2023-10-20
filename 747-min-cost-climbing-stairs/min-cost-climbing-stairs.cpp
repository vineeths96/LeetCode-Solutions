class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> dpVector(cost.size() + 1, std::numeric_limits<int>::max());

        dpVector[cost.size()] = 0;
        for (int i = cost.size() - 1; i >= 0; i--) { 
            int oneStep = std::numeric_limits<int>::max(), twoStep = std::numeric_limits<int>::max();
            oneStep = dpVector[i + 1];
            if (i + 2 <= cost.size())
                twoStep = dpVector[i + 2];

            dpVector[i] = cost[i] + std::min(oneStep, twoStep);
        }

        return std::min(dpVector[0], dpVector[1]);
    }
};