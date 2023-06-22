class Solution {
private:
    int dfs(const std::vector<std::vector<int>> &grid, std::vector<std::vector<bool>> &visited, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return 1;

        if (grid[x][y] == 0)
            return 1;

        if (visited[x][y])
            return 0;

        visited[x][y] = true;
        return dfs(grid, visited, x - 1, y) + 
               dfs(grid, visited, x + 1, y) + 
               dfs(grid, visited, x, y - 1) + 
               dfs(grid, visited, x, y + 1); 
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));

        int perimeter = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 0)
                    continue;    

                if (visited[i][j])
                    continue;    

                perimeter += dfs(grid, visited, i, j);
            }
        }

        return perimeter;
    }
};