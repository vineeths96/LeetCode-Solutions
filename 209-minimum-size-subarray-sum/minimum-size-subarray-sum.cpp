class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minWindowLength = std::numeric_limits<int>::max();
        int windowStart = 0;
        int windowSum = 0;

        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            windowSum += nums[windowEnd];

            while (windowStart <= windowEnd && windowSum >= target) {
                minWindowLength = std::min(minWindowLength, windowEnd - windowStart + 1);
                windowSum -= nums[windowStart++];
            }
        }

        return windowStart == 0 ? 0 : minWindowLength;
    }
};