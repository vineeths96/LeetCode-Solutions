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
        if (maxHeap.top().second > (s.size() + 1) / 2) 
            return reorgedString;

        reorgedString.reserve(s.size());
        while (!maxHeap.empty()) {
            auto firstKvPair = maxHeap.top();
            maxHeap.pop();            
            reorgedString += firstKvPair.first;
            firstKvPair.second--;
            
            if (!maxHeap.empty()) {
                auto secondKvPair = maxHeap.top();
                maxHeap.pop();
                reorgedString += secondKvPair.first;
                secondKvPair.second--;

                if (firstKvPair.second > 0) maxHeap.push(firstKvPair);
                if (secondKvPair.second > 0) maxHeap.push(secondKvPair);
            }
        }

        return reorgedString;
    }
};