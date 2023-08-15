class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int numClosedIslands = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    continue;

                bool boundaryHit = false;
                std::stack<std::pair<int, int>> dfsStack;
                dfsStack.push(std::make_pair(i, j));
                grid[i][j] = 1;

                while (!dfsStack.empty()) {
                    auto top = dfsStack.top();
                    dfsStack.pop();

                    int x = top.first;
                    int y = top.second;

                    if (x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1)
                        boundaryHit = true;

                    if (x > 0 && grid[x-1][y] == 0) {
                        dfsStack.push(std::make_pair(x - 1, y));
                        grid[x-1][y] = 1;
                    }

                    if (x < grid.size() - 1 && grid[x+1][y] == 0) {
                        dfsStack.push(std::make_pair(x + 1, y));
                        grid[x+1][y] = 1;
                    }

                    if (y > 0 && grid[x][y-1] == 0) {
                        dfsStack.push(std::make_pair(x, y - 1));
                        grid[x][y-1] = 1;
                    }

                    if (y < grid[0].size() - 1 && grid[x][y+1] == 0) {
                        dfsStack.push(std::make_pair(x, y + 1));
                        grid[x][y+1] = 1;
                    }
                }

                if (!boundaryHit)
                    numClosedIslands++;
            }
        }

        return numClosedIslands;
    }
};