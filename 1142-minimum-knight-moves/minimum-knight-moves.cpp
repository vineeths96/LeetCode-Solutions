class Solution {
    std::map<std::pair<int, int>, int> dp;

    int findStepsToOrigin(int x, int y) {
        if (x + y == 0)
            return 0;
        else if (x + y == 2)
            return 2;

        if (dp.contains({x, y}))
            return dp[{x, y}];

        int steps = std::min(findStepsToOrigin(std::abs(x - 1), std::abs(y - 2)), findStepsToOrigin(std::abs(x - 2), std::abs(y - 1))) + 1;        

        return dp[{x, y}] = steps;
    }

public:
    int minKnightMoves(int x, int y) {
        return findStepsToOrigin(std::abs(x), std::abs(y));
    }
};