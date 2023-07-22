class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int oneCount = 0;
        int maxConsecutiveOnes = std::numeric_limits<int>::min();
        
        for (int windowStart = 0, windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            oneCount += nums[windowEnd];

            while (windowEnd - windowStart + 1 - oneCount > k) {
                oneCount -= nums[windowStart];
                windowStart++;
            }

            maxConsecutiveOnes = std::max(maxConsecutiveOnes, windowEnd - windowStart + 1);
        }

        return maxConsecutiveOnes;
    }
};