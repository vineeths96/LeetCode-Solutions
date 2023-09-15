class Solution {
    struct Compare {
        bool operator()(const std::pair<char, int> &X, const std::pair<char, int> &Y) {
            return X.second < Y.second;
        }
    };

public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> charFreqMap;
        for (const char &ch : tasks)
            charFreqMap[ch]++;

        std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, Compare> maxHeap;
        for (const auto &kvPair : charFreqMap)
            maxHeap.push(kvPair);

        std::queue<std::pair<char, int>> previousEntries;
        int timeUnits = 0;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();
            timeUnits++;
            top.second--;

            previousEntries.push(top);
            if (previousEntries.size() > n) {
                auto front = previousEntries.front();
                previousEntries.pop();

                if (front.second > 0) 
                    maxHeap.push(front);
            }

            if (maxHeap.empty() && !previousEntries.empty()) {
                while (!previousEntries.empty() && previousEntries.front().second <= 0) 
                    previousEntries.pop();

                if (!previousEntries.empty() && previousEntries.front().second > 0)
                    maxHeap.push({' ', 0});
            }
        }

        return timeUnits;
    }
};