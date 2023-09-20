class Solution {
    std::vector<int> countElementsLessThanEquals(std::vector<std::vector<int>> &matrix, int mid) {
        int i = matrix.size() - 1;
        int j = 0;

        std::vector<int> countValueVec({0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()});
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] <= mid) {
                countValueVec[0] += i + 1;
                countValueVec[1] = std::max(countValueVec[1], matrix[i][j]);
                j++;
            }
            else {
                countValueVec[2] = std::min(countValueVec[2], matrix[i][j]);
                i--;
            }
        }

        return countValueVec;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0];
        int right = matrix[matrix.size() - 1][matrix[0].size() - 1];

        while (left < right) {
            int mid = left + (right - left) / 2;

            auto countValueVec = countElementsLessThanEquals(matrix, mid);
            
            if (countValueVec[0] == k)
                return countValueVec[1];
            else if (countValueVec[0] < k)
                left = countValueVec[2];
            else 
                right = countValueVec[1];
        }

        return left;
    }
};