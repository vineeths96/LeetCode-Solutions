class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int onesCount = 0;
        int maxWindow = std::numeric_limits<int>::min();
        for (int windowStart = 0, windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            onesCount += nums[windowEnd];

            if (windowStart <= windowEnd && windowEnd - windowStart + 1 - onesCount > 1) {
                onesCount -= nums[windowStart];
                windowStart++;
            }

            maxWindow = std::max(maxWindow, windowEnd - windowStart + 1);
        }

        return maxWindow;
    }
};