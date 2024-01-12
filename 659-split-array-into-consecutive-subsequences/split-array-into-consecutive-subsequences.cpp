class Solution {
public:
    bool isPossible(vector<int>& nums) {
        std::unordered_map<int, int> freqMap;
        std::unordered_map<int, int> sequenceMap;

        for (const int &num : nums)
            freqMap[num]++;

        for (const int &num : nums) {
            if (freqMap[num] == 0)
                continue;

            if (sequenceMap[num - 1] > 0) {
                sequenceMap[num]++;
                sequenceMap[num - 1]--;
            } else if (freqMap[num + 1] > 0 && freqMap[num + 2] > 0) {
                freqMap[num + 1]--;
                freqMap[num + 2]--;
                sequenceMap[num + 2]++;
            } else
                return false;

            freqMap[num]--;
        }

        return true;
    }
};