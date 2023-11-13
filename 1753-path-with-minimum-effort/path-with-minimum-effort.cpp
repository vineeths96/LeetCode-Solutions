class Solution {
    struct Cell {
        int x;
        int y;
        int effort;

        Cell(int x, int y, int effort) : x(x), y(y), effort(effort) {};
    };

    struct Compare {
        bool operator()(const Cell &A, const Cell &B) {
            return A.effort > B.effort;
        }
    };

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();

        std::vector<std::vector<int>> effortMatrix(rows, std::vector<int>(columns, std::numeric_limits<int>::max()));
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));
        std::priority_queue<Cell, std::vector<Cell>, Compare> minHeap;

        int dirX[] = {0, 1, 0, -1};
        int dirY[] = {1, 0, -1, 0};
        
        effortMatrix[0][0] = 0;
        minHeap.push(Cell(0, 0, effortMatrix[0][0]));

        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();

            int x = top.x;
            int y = top.y;
            int currentEffort = top.effort;
            visited[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int xDash = x + dirX[i];
                int yDash = y + dirY[i];

                if (xDash < 0 || xDash >= rows || yDash < 0 || yDash >= columns)
                    continue;

                int nextEffort = std::abs(heights[xDash][yDash] - heights[x][y]);
                int candidateEffort = std::max(nextEffort, currentEffort);
                if (!visited[xDash][yDash] && effortMatrix[xDash][yDash] > candidateEffort) {
                    effortMatrix[xDash][yDash] = candidateEffort;
                    minHeap.push(Cell(xDash, yDash, effortMatrix[xDash][yDash]));
                }
            }
        }

        return effortMatrix[rows - 1][columns - 1];
    }
};