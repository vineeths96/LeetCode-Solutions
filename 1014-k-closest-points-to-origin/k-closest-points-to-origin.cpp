class Solution {
    int distance(const std::vector<int> &point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    int partition(std::vector<std::vector<int>> &points, int start, int end) {
        int pivot = start;
        for (int i = start; i < end; i++) {
            if (distance(points[i]) <= distance(points[end]))
                std::swap(points[i], points[pivot++]);
        }
        std::swap(points[end], points[pivot]);

        return pivot;
    }

    void quickSelect(std::vector<std::vector<int>> &points, int start, int end, int k) {
        if (start >= end) return;
        
        int pivot = partition(points, start, end);
        if (k == pivot) return;
        else if (k < pivot) quickSelect(points, start, pivot - 1, k);
        else quickSelect(points, pivot + 1, end, k);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(points, 0, points.size() - 1, k);
        return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
    }
};