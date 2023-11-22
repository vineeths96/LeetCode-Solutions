class Solution {
    int rows;
    int cols;

    std::vector<std::vector<bool>> bfsOcean(const std::vector<std::vector<int>> &heights, std::queue<std::pair<int, int>> &bfsQueue) {
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        
        int dirX[] = {0, -1, 0, 1};
        int dirY[] = {1, 0, -1, 0}; 

        while (!bfsQueue.empty()) {
            auto [x, y] = bfsQueue.front();
            bfsQueue.pop();

            visited[x][y] = true;
            for (int k = 0; k < 4; k++) {
                int xDash = x + dirX[k];
                int yDash = y + dirY[k];

                if (xDash < 0 || xDash >= rows || yDash < 0 || yDash >= cols || heights[x][y] > heights[xDash][yDash])
                    continue;

                if (!visited[xDash][yDash])
                    bfsQueue.push({xDash, yDash});
            }
        }

        return visited;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        
        std::queue<std::pair<int, int>> pacificQueue;
        std::queue<std::pair<int, int>> atlanticQueue;

        for (int i = 0; i < rows; i++) {
            pacificQueue.push({i, 0});
            atlanticQueue.push({i, cols - 1});
        }

        for (int j = 0; j < cols; j++) {
            pacificQueue.push({0, j});
            atlanticQueue.push({rows - 1, j});
        }

        auto pacificVisited = bfsOcean(heights, pacificQueue);
        auto atlanticVisited = bfsOcean(heights, atlanticQueue);

        std::vector<std::vector<int>> results;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j])
                    results.push_back({i, j});
            }
        }

        return results;
    }
};