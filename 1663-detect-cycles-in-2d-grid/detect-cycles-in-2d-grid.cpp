class Solution {
private:
    bool dfs(const std::vector<std::vector<char>> &grid, std::vector<std::vector<bool>> &visited, 
            int x, int y, int xprev, int yprev) {
        visited[x][y] = true;

        int dirx[] = {0, 1, 0, -1};
        int diry[] = {1, 0, -1, 0};

        for (int k = 0; k < 4; k++) {
            int xdash = x + dirx[k];
            int ydash = y + diry[k];

            if(xdash < 0 || xdash >= grid.size() || ydash < 0 || ydash >= grid[0].size())
                continue;

            if (grid[xdash][ydash] != grid[x][y])
                continue;

            if (visited[xdash][ydash]) {
                if (xdash != xprev || ydash != yprev)
                    return true;
            } else {
                if(dfs(grid, visited, xdash, ydash, x, y))
                    return true; 
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (visited[i][j])
                    continue;

                if(Solution::dfs(grid, visited, i, j, -1, -1))
                    return true;
            }
        }

        return false;
    }
};
