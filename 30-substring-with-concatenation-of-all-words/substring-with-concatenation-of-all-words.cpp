class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::unordered_map<std::string, int> wordFreqMap;
        for (const auto &word : words)
            wordFreqMap[word]++;

        int numWords = words.size();
        int wordSize = words[0].size();
        std::vector<int> startingIndices;
        for (int i = 0; i < wordSize; i++) {
            int matched = 0;
            std::unordered_map<std::string, int> windowWordFreqMap;
            for (int windowStart = i, windowEnd = i; windowEnd < s.size(); windowEnd = windowEnd + wordSize) {
                std::string word = s.substr(windowEnd, wordSize);

                if (wordFreqMap.find(word) == wordFreqMap.end()) {
                    windowStart = windowEnd + wordSize;
                    windowWordFreqMap.clear();
                    matched = 0;
                } else {
                    windowWordFreqMap[word]++;
                    
                    if (windowWordFreqMap[word] == wordFreqMap[word]) {
                        matched++;

                        if (matched == wordFreqMap.size())
                            startingIndices.push_back(windowStart);
                    }

                    while (matched == wordFreqMap.size() || windowStart < windowEnd && windowWordFreqMap[word] > wordFreqMap[word]) {
                        std::string outgoingWord = s.substr(windowStart, wordSize);
                        windowWordFreqMap[outgoingWord]--;
                        windowStart += wordSize;                
            
                        if (windowWordFreqMap[outgoingWord] == wordFreqMap[outgoingWord] - 1)
                            matched--;
                    }
                }
            }
        }

        return startingIndices;
    }
};