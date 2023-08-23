/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

struct Compare {
    bool operator()(const std::pair<int, Interval> &A, const std::pair<int, Interval> &B) {
        return A.second.start > B.second.start;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        std::priority_queue<std::pair<int, Interval>, std::vector<std::pair<int, Interval>>, Compare> pQueue;
        std::vector<int> lastPushedIndex(schedule.size(), 0);

        for (int employee = 0; employee < schedule.size(); employee++)
            pQueue.push({employee, schedule[employee][0]});

        std::vector<Interval> freetime;
        Interval previous = pQueue.top().second;
        while (!pQueue.empty()) {
            auto top = pQueue.top();
            pQueue.pop();

            int employee = top.first;
            Interval interval = top.second;

            if (previous.end < interval.start) {
                freetime.push_back(Interval(previous.end, interval.start));
                previous.end = interval.end;
            } else
                previous.end = std::max(previous.end, interval.end);

            if (lastPushedIndex[employee] < schedule[employee].size() - 1) {
                pQueue.push({employee, schedule[employee][lastPushedIndex[employee] + 1]});
                lastPushedIndex[employee]++;
            }
 
        }

        return freetime;
    }
};