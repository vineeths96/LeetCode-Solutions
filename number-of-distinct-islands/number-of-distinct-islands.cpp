class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        std::set<std::vector<std::pair<int, int>>> pathTracker;
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0 || visited[i][j])
                    continue;

                int time = 0;
                std::vector<std::pair<int, int>> path;
                std::stack<std::pair<int, int>> dfsStack;
                dfsStack.push(std::make_pair(i, j));
                visited[i][j] = true;

                while (!dfsStack.empty()) {
                    auto top = dfsStack.top();
                    dfsStack.pop();
                    time++;

                    int x = top.first;
                    int y = top.second;

                    if (x > 0 && grid[x-1][y] == 1 && !visited[x-1][y]) {
                        dfsStack.push(std::make_pair(x - 1, y));
                        visited[x-1][y] = true;
                        path.push_back(std::make_pair(time, 1));
                    }

                    if (x < grid.size() - 1 && grid[x+1][y] == 1 && !visited[x+1][y]) {
                        dfsStack.push(std::make_pair(x + 1, y));
                        visited[x+1][y] = true;
                        path.push_back(std::make_pair(time, 2));
                    }

                    if (y > 0 && grid[x][y-1] == 1 && !visited[x][y-1]) {
                        dfsStack.push(std::make_pair(x, y - 1));
                        visited[x][y-1] = true;
                        path.push_back(std::make_pair(time, 3));
                    }

                    if (y < grid[0].size() - 1 && grid[x][y+1] == 1 && !visited[x][y+1]) {
                        dfsStack.push(std::make_pair(x, y + 1));
                        visited[x][y+1] = true;
                        path.push_back(std::make_pair(time, 4));
                    }
                }

                pathTracker.insert(path);
            }
        }

        return pathTracker.size();
    }
};