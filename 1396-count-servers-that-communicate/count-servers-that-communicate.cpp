class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        std::vector<int> rowCounts(rows, 0);
        std::vector<int> colCounts(cols, 0);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0)
                    continue;

                rowCounts[i]++;
                colCounts[j]++;
            }
        }

        int servers = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0)
                    continue;

                if (rowCounts[i] > 1 || colCounts[j] > 1)
                    servers++;
            }
        }

        return servers;
    }
};