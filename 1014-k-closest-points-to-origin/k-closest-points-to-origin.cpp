class Solution {
    static int distance(const std::vector<int> &point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    struct Compare {
        bool operator()(const std::vector<int> &X, const std::vector<int> &Y) {
            return distance(X) < distance(Y);
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Compare> maxHeap;

        for (int i = 0; i < points.size(); i++) {
            if (i < k) {
                maxHeap.push(points[i]);
                continue;
            }

            if (distance(points[i]) < distance(maxHeap.top())) {
                maxHeap.pop();
                maxHeap.push(points[i]);
            }
        }

        std::vector<std::vector<int>> kClosePoints;
        while (!maxHeap.empty()) {
            kClosePoints.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return kClosePoints;
    }
};