class Solution {
    struct CompareStart {
        bool operator()(const std::vector<int> a, const std::vector<int> b) {
            return a[0] < b[0];
        }
    };

    struct CompareEnd {
        bool operator()(const std::vector<int> a, const std::vector<int> b) {
            return a[1] < b[1];
        }
    };

public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, CompareStart> startingHeap;
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, CompareEnd> endingHeap;

        for (int i = 0; i < intervals.size(); i++) {
            startingHeap.push({intervals[i][0], intervals[i][1], i});
            endingHeap.push({intervals[i][0], intervals[i][1], i});
        }

        std::vector<int> nextInterval(intervals.size(), -1);
        for (int i = 0; i < intervals.size(); i++) {
            std::vector<int> endInterval = endingHeap.top();
            endingHeap.pop();

            std::vector<int> startInterval({std::numeric_limits<int>::min(), std::numeric_limits<int>::min(), -1});
            while (!startingHeap.empty() && endInterval[1] <= startingHeap.top()[0]) {
                startInterval = startingHeap.top();
                startingHeap.pop();
            }

            nextInterval[endInterval[2]] = startInterval[2];
            startingHeap.push(startInterval);
        }

        return nextInterval;
    }
};