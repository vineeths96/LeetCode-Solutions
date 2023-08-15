class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 1)
                    continue;

                int currentArea = 0;
                std::queue<std::pair<int, int>> bfsQueue;
                bfsQueue.push(std::make_pair(i, j));
                grid[i][j] = 0;

                while (!bfsQueue.empty()) {
                    auto front = bfsQueue.front();
                    bfsQueue.pop();
                    currentArea++;

                    int x = front.first;
                    int y = front.second;

                    if (x > 0 && grid[x-1][y] == 1) {
                        bfsQueue.push(std::make_pair(x - 1, y));
                        grid[x-1][y] = 0;
                    }

                    if (x < grid.size() - 1 && grid[x+1][y] == 1) {
                        bfsQueue.push(std::make_pair(x + 1, y));
                        grid[x+1][y] = 0;
                    }

                    if (y > 0 && grid[x][y-1] == 1) {
                        bfsQueue.push(std::make_pair(x, y - 1));
                        grid[x][y-1] = 0;
                    }

                    if (y < grid[0].size() - 1 && grid[x][y+1] == 1) {
                        bfsQueue.push(std::make_pair(x, y + 1));
                        grid[x][y+1] = 0;
                    }
                }

                maxArea = std::max(maxArea, currentArea);
            }
        }

        return maxArea;
    }
};