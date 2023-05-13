class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        int islandCount = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (visited[i][j])
                    continue;

                if (grid[i][j] == '0')
                    continue;

                std::stack<std::pair<int, int>> dfsStack;
                dfsStack.push(std::make_pair(i, j));
                visited[i][j] = true;

                while (!dfsStack.empty()) {
                    auto top = dfsStack.top();
                    dfsStack.pop();

                    int x = top.first;
                    int y = top.second;

                    if (x > 0 && grid[x-1][y] == '1' && visited[x-1][y] == false) {
                        dfsStack.push(std::make_pair(x - 1, y));
                        visited[x-1][y] = true;
                    }

                    if (x < grid.size() - 1 && grid[x+1][y] == '1' && visited[x+1][y] == false) {
                        dfsStack.push(std::make_pair(x + 1, y));
                        visited[x+1][y] = true;
                    }

                    if (y > 0 && grid[x][y-1] == '1' && visited[x][y-1] == false) {
                        dfsStack.push(std::make_pair(x, y - 1));
                        visited[x][y-1] = true;
                    }

                    if (y < grid[0].size() - 1 && grid[x][y+1] == '1' && visited[x][y+1] == false) {
                        dfsStack.push(std::make_pair(x, y + 1));
                        visited[x][y+1] = true;
                    }
                }

                islandCount++;                
            }
        }

        return islandCount;
    }
};