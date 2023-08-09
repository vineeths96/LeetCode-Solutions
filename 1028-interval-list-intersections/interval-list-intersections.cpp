class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        std::vector<std::vector<int>> intersectedIntervals;
        int firstListIndex = 0;
        int secondListIndex = 0;

        while (firstListIndex < firstList.size() && secondListIndex < secondList.size()) {
            int start = std::max(firstList[firstListIndex][0], secondList[secondListIndex][0]);
            int end = std::min(firstList[firstListIndex][1], secondList[secondListIndex][1]);
            if (end - start >= 0) intersectedIntervals.push_back({start, end});

            firstList[firstListIndex][1] < secondList[secondListIndex][1] ? firstListIndex++ : secondListIndex++;
        }

        return intersectedIntervals;
    }
};