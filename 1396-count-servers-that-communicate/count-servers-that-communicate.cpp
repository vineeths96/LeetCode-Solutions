class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int servers = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0)
                    continue;

                int serversInCol = 0;
                for (int iDash = 0; iDash < rows; iDash++) 
                    if (grid[iDash][j] == 1) 
                        serversInCol++;
                
                int serversInRow = 0;
                for (int jDash = 0; jDash < cols; jDash++)
                    if (grid[i][jDash] == 1)
                        serversInRow++;

                if (serversInRow > 1 || serversInCol > 1)
                    servers++;
            }
        }

        return servers;
    }
};