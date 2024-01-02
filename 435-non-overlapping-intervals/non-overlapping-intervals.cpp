class Solution {
    static bool compare(const std::vector<int> &A, const std::vector<int> &B) {
        return A[0] < B[0] || (A[0] == B[0] && A[1] < B[1]);
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), compare);

        int numIntervals = 0;
        int lastIntervalEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= lastIntervalEnd) 
                lastIntervalEnd = intervals[i][1];
            else {
                numIntervals++;
                lastIntervalEnd = std::min(lastIntervalEnd, intervals[i][1]);
            }
        }

        return numIntervals;
    }
};