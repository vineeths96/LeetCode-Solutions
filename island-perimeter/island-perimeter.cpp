class Solution {
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

                std::stack<std::pair<int, int>> dfsStack;
                dfsStack.push(std::make_pair(i, j));
                visited[i][j] = true;

                while (!dfsStack.empty()) {
                    auto top = dfsStack.top();
                    dfsStack.pop();

                    int x = top.first;
                    int y = top.second;

                    int dirx[] = {-1, 0, 1, 0};
                    int diry[] = {0, -1, 0, 1};

                    for (int k = 0; k < 4; k++) {
                        int xdash = x + dirx[k];
                        int ydash = y + diry[k];

                        if (xdash < 0 || xdash >= grid.size() || y < 0 || ydash >= grid[0].size()) {
                            perimeter++;
                            continue;
                        }
                        
                        if (grid[xdash][ydash] == 0)
                            perimeter++;
                        else if (!visited[xdash][ydash]) {
                            dfsStack.push(std::make_pair(xdash, ydash));
                            visited[xdash][ydash] = true;
                        }
                    }
                }
            }
        }

        return perimeter;
    }
};