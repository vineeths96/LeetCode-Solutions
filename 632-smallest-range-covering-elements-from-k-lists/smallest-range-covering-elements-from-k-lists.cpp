class Solution {
    struct Compare {
        bool operator()(const std::pair<int, std::pair<int, int>> &A, const std::pair<int, std::pair<int, int>> &B) {
            return A.first > B.first;
        }
    };

public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, Compare> minHeap;
        int maxValuePushed = std::numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i].empty()) {
                minHeap.push({nums[i][0], {i, 0}});
                maxValuePushed = std::max(maxValuePushed, nums[i][0]);
            }
        }

        std::vector<int> range({minHeap.top().first, maxValuePushed});
        while (minHeap.size() == nums.size()) {
            auto top = minHeap.top();
            minHeap.pop();

            if (maxValuePushed - top.first < range[1] - range[0])
                range = {top.first, maxValuePushed};

            top.second.second++;
            if (top.second.second < nums[top.second.first].size()) {
                minHeap.push({nums[top.second.first][top.second.second], {top.second.first, top.second.second}});
                maxValuePushed = std::max(maxValuePushed, nums[top.second.first][top.second.second]);
            }
        }

        return range;
    }
};