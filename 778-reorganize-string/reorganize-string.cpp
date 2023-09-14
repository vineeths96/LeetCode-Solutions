class Solution {
    struct Compare {
        bool operator()(std::pair<char, int> X, std::pair<char, int> Y) {
            return X.second < Y.second;
        }
    };
public:
    string reorganizeString(string s) {
        std::unordered_map<char, int> charFreqMap;
        for (const char &ch : s)
            charFreqMap[ch]++;

        std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, Compare> maxHeap;
        for (const auto kvPair : charFreqMap)
            maxHeap.push(kvPair);

        std::string reorgedString;
        reorgedString.reserve(s.size());
        if (maxHeap.top().second > (s.size() + 1) / 2) 
            return reorgedString;

        std::pair<char, int> previousPair({' ', -1});
        while (!maxHeap.empty()) {
            auto kvPair = maxHeap.top();
            maxHeap.pop();            
            reorgedString += kvPair.first;
            kvPair.second--;

            if (previousPair.second > 0) maxHeap.push(previousPair);
            previousPair = kvPair;
        }

        return reorgedString;
    }
};