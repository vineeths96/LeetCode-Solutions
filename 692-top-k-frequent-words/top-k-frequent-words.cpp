class Solution {
    struct Pair {
        int frequency;
        std::string word;

        Pair(int frequency, std::string word) : frequency(frequency), word(word) {}
    };

    struct Compare {
        bool operator() (const Pair &A, const Pair &B) {
            return A.frequency > B.frequency || (A.frequency == B.frequency && A.word < B.word);
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string, int> freqMap;
        for (const std::string &word : words)
            freqMap[word]++;

        std::priority_queue<Pair, std::vector<Pair>, Compare> minHeap;
        for (const auto &kvPair : freqMap) {
            minHeap.push(Pair(kvPair.second, kvPair.first));

            if (minHeap.size() > k)
                minHeap.pop();
        }

        std::vector<std::string> topK;
        while (!minHeap.empty()) {
            topK.push_back(minHeap.top().word);
            minHeap.pop();
        }

        std::reverse(topK.begin(), topK.end());
        return topK;
    }
};