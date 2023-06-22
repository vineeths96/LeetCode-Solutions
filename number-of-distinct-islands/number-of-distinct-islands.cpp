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

                    int dirx[] = {1, 0, -1, 0};
                    int diry[] = {0, 1, 0, -1};

                    for (int k = 0; k < 4; k++) {
                        int xdash = x + dirx[k];
                        int ydash = y + diry[k];

                        if (xdash < 0 || xdash >= grid.size() || ydash < 0 || ydash >= grid[0].size())
                            continue;

                        if (grid[xdash][ydash] == 1 && !visited[xdash][ydash]) {
                            dfsStack.push(std::make_pair(xdash, ydash));
                            visited[xdash][ydash] = true;
                            path.push_back(std::make_pair(time, k));
                        }

                    }
                }

                pathTracker.insert(path);
            }
        }

        return pathTracker.size();
    }
};