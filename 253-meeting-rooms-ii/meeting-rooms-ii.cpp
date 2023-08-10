class Solution {
    struct compare {
        bool operator()(int a, int b) {
            return a > b;
        }
    };
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        int rooms = 0;
        std::priority_queue<int, std::vector<int>, compare> minHeap;

        for (const auto &interval : intervals) {
            while (!minHeap.empty() && minHeap.top() <= interval[0])
                minHeap.pop();

            minHeap.push(interval[1]);
            rooms = std::max(rooms, static_cast<int>(minHeap.size()));
        }

        return rooms;
    }
};