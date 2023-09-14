class Solution {
    struct Compare {
        bool operator()(std::pair<int, int> X, std::pair<int, int> Y) {
            return X.second > Y.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap;
        for (const int &num : nums)
            freqMap[num]++;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> minHeap;
        for (const std::pair<int, int> kvPair : freqMap) {
            if (minHeap.size() < k)
                minHeap.push(kvPair);
            else {
                if (kvPair.second > minHeap.top().second) {
                    minHeap.pop();
                    minHeap.push(kvPair);
                }
            }
        }

        std::vector<int> topkFreq;
        while (!minHeap.empty()) {
            topkFreq.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return topkFreq;
    }
};