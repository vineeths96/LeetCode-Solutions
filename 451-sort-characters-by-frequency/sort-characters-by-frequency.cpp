class Solution {
    struct Compare {
        bool operator()(std::pair<char, int> X, std::pair<char, int> Y) {
            return X.second < Y.second;
        }
    };

public:
    string frequencySort(string s) {
        std::unordered_map<char, int> charFreqMap;
        for (const char &ch : s)
            charFreqMap[ch]++;

        std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, Compare> maxHeap;
        for (const auto kvPair : charFreqMap)
            maxHeap.push(kvPair);

        std::string sortedString;
        sortedString.reserve(s.size());
        while (!maxHeap.empty()) {
            auto kvPair = maxHeap.top();
            maxHeap.pop();
            sortedString.append(kvPair.second, kvPair.first);
        }

        return sortedString;
    }
};