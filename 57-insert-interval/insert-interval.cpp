class Solution {
    void insertInterval(std::vector<std::vector<int>> &insertedIntervals, std::vector<int> &newInterval) {
        if (insertedIntervals.empty() || newInterval[0] > insertedIntervals.back()[1])
            insertedIntervals.push_back(newInterval);
        else
            insertedIntervals.back()[1] = std::max(insertedIntervals.back()[1], newInterval[1]);
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int idxToInsert = 0;
        while (idxToInsert < intervals.size() && intervals[idxToInsert][0] < newInterval[0])
            idxToInsert++;

        std::vector<std::vector<int>> insertedIntervals;
        for (int current = 0; current < idxToInsert; current++)
            insertedIntervals.push_back(intervals[current]);

        insertInterval(insertedIntervals, newInterval);
        for (int current = idxToInsert; current < intervals.size(); current++)
            insertInterval(insertedIntervals, intervals[current]);

        return insertedIntervals;        
    }
};