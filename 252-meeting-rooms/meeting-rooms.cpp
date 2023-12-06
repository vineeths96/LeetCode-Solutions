class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        auto compare = [](const std::vector<int> &A, const std::vector<int> &B){return A[0] < B[0];};
        std::sort(intervals.begin(), intervals.end(), compare);

        for (int i = 1; i < intervals.size(); i++)
            if (intervals[i][0] < intervals[i - 1][1])
                return false;

        return true;
    }
};