class Solution {
    class CircularQueue {
        std::vector<int> queue;
        int head;
        int tail;
        int numElements;

    public:
        CircularQueue(int numElements) {
            this->numElements = numElements;
            this->head = 0;
            this->tail = 0;
            queue = std::vector<int>(numElements);
        }

        void enQueue(int val) {
            queue[tail % numElements] = val;
            tail = ++tail % numElements;
        }

        void deQueue() {
            head = ++head % numElements;
        }

        int getIndex(int index) {
            return queue[index % numElements];
        }
    };

    int rows;
    int cols;

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        rows = dungeon.size();
        cols = dungeon[0].size();

        CircularQueue dp = CircularQueue(cols);

        auto getHealth = [&](int i, int j, int iDash, int jDash) {
          if (iDash >= rows || jDash >= cols)
            return std::numeric_limits<int>::max();

          return std::max(1, dp.getIndex(cols - 1 - jDash) - dungeon[i][j]);
        };

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                int right = getHealth(i, j, i, j + 1);
                int below = getHealth(i, j, i + 1, j);

                int minVal = std::min(right, below);
                dp.enQueue(minVal == std::numeric_limits<int>::max() ? std::max(1, 1 - dungeon[i][j]) : minVal);
            }
        }

        return dp.getIndex(cols - 1);
    }
};