class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::array<int, 26> lastSeenIndex;

        for (int i = 0; i < s.size(); i++)
            lastSeenIndex[s[i] - 'a'] = i;

        int currentStart = 0, currentEnd = 0;
        std::vector<int> partitions;
        for (int i = 0; i < s.size(); i++) {
            currentEnd = std::max(currentEnd, lastSeenIndex[s[i] - 'a']);
            
            if (i == currentEnd) {
                partitions.push_back(currentEnd - currentStart + 1);
                currentStart = i + 1;
            }
        }

        return partitions;
    }
};