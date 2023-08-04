class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        std::vector<std::vector<int>> intersectedIntervals;
        int firstListIndex = 0;
        int secondListIndex = 0;

        while (firstListIndex < firstList.size() && secondListIndex < secondList.size()) {
            if (firstList[firstListIndex][1] < secondList[secondListIndex][0]) {
                firstListIndex++;
                continue;
            }

            if (secondList[secondListIndex][1] < firstList[firstListIndex][0]) {
                secondListIndex++;
                continue;
            }

            int start = std::max(firstList[firstListIndex][0], secondList[secondListIndex][0]);
            int end = std::min(firstList[firstListIndex][1], secondList[secondListIndex][1]);
            intersectedIntervals.push_back({start, end});

            firstList[firstListIndex][1] < secondList[secondListIndex][1] ? firstListIndex++ : secondListIndex++;
        }

        return intersectedIntervals;
    }
};