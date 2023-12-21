class Solution {
    struct Cell {
        int x;
        int y;
        int val;

        Cell(int x, int y, int val) : x(x), y(y), val(val) {}
    };

    struct Compare {
        bool operator()(const Cell &A, const Cell &B) {
            return A.val < B.val;
        }
    };

public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        std::vector<std::vector<int>> valMatrix(rows, std::vector<int>(cols, std::numeric_limits<int>::min()));
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        std::priority_queue<Cell, std::vector<Cell>, Compare> maxHeap;

        std::vector<std::vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        valMatrix[0][0] = grid[0][0];
        maxHeap.push(Cell(0, 0, valMatrix[0][0]));

        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();

            auto [x, y, val] = top;
            visited[x][y] = true;

            for (const auto &dir : dirs) {
                int xDash = x + dir[0];
                int yDash = y + dir[1];

                if (xDash < 0 || xDash >= rows || yDash < 0 || yDash >= cols)
                    continue;

                int newVal = std::min(val, grid[xDash][yDash]);
                if (!visited[xDash][yDash] && valMatrix[xDash][yDash] < newVal) {
                    valMatrix[xDash][yDash] = newVal;
                    maxHeap.push(Cell(xDash, yDash, valMatrix[xDash][yDash]));
                }
            }
        }

        return valMatrix.back().back();
    }
};