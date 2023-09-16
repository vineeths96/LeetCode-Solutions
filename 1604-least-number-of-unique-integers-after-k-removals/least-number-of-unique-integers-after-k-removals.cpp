class Solution {
    struct Compare {
        bool operator()(const std::pair<int, int> &X, const std::pair<int, int> &Y) {
            return X.second > Y.second;
        }
    };

public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::unordered_map<int, int> freqMap;
        for (const int &num : arr)
            freqMap[num]++;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> minHeap;
        for (const auto kvPair : freqMap)
            minHeap.push(kvPair);

        while (!minHeap.empty() && k) {
            if (k < minHeap.top().second)
                break;
            
            k -= minHeap.top().second;
            minHeap.pop();
        }

        return minHeap.size();
    }
};