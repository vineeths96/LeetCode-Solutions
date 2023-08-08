class Solution {
    static bool compare(std::vector<int> vecA, std::vector<int> vecB) {
        return vecA[0] < vecB[0] || vecA[0] == vecB[0] && vecA[1] < vecB[1];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> mergedIntervals;
        std::sort(intervals.begin(), intervals.end(), compare);

        for (int ind = 0; ind < intervals.size(); ind++) {
            std::vector<int> &currentInterval = intervals[ind];
            if (mergedIntervals.empty() || currentInterval[0] >  mergedIntervals.back()[1])
                mergedIntervals.push_back(currentInterval);
            else
                mergedIntervals.back()[1] = std::max(mergedIntervals.back()[1], currentInterval[1]);
        }

        return mergedIntervals;
    }
};