class Solution {
    int rows;
    int cols;

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        rows = dungeon.size();
        cols = dungeon[0].size();

        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));

        auto getHealth = [&](int i, int j, int iDash, int jDash) {
          if (iDash >= rows || jDash >= cols)
            return std::numeric_limits<int>::max();

          return std::max(1, dp[iDash][jDash] - dungeon[i][j]);
        };

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                int right = getHealth(i, j, i, j + 1);
                int below = getHealth(i, j, i + 1, j);

                int minVal = std::min(right, below);
                dp[i][j] = minVal == std::numeric_limits<int>::max() ? std::max(1, 1 - dungeon[i][j]) : minVal;
            }
        }

        return dp[0][0];
    }
};