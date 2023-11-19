class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        std::map<int, int> freqMap;
        int maxLength = 0;

        for (int windowStart = 0, windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            freqMap[nums[windowEnd]]++;

            if (freqMap.rbegin()->first - freqMap.begin()->first > limit) {
                freqMap[nums[windowStart]]--;
                if (freqMap[nums[windowStart]] == 0)
                    freqMap.erase(nums[windowStart]);

                windowStart++;
            }

            maxLength = std::max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};