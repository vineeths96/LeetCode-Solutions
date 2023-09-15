class Solution {
    struct Compare {
        bool operator()(const std::pair<char, int> &X, const std::pair<char, int> &Y) {
            return X.second < Y.second;
        }
    };

public:
    string rearrangeString(string s, int k) {
        if (k == 0) return s;

        std::unordered_map<char, int> charFreqMap;
        for (const char &ch : s)
            charFreqMap[ch]++;

        std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, Compare> maxHeap;
        for (const auto &kvPair : charFreqMap)
            maxHeap.push(kvPair);

        std::queue<std::pair<char, int>> previousEntries;
        std::string rearrangedString;
        rearrangedString.reserve(s.size());
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();
            rearrangedString += top.first;
            top.second--;

            previousEntries.push(top);            
            if (previousEntries.size() == k) {
                auto front = previousEntries.front();
                previousEntries.pop();

                if (front.second > 0) 
                    maxHeap.push(front);
            }
        }

        return rearrangedString.size() == s.size() ? rearrangedString : "";
    }
};