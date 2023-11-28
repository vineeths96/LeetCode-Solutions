class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        int end = rows * cols - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            int rowInd = mid / cols;
            int colInd = mid % cols;

            if (matrix[rowInd][colInd] > target)
                end = mid - 1;
            else if (matrix[rowInd][colInd] < target)
                start = mid + 1;
            else
                return true;
        }

        return false;
    }
};