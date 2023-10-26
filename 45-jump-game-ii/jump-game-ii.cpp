class Solution {
public:
    int jump(vector<int>& nums) {
        int currentRangeEnd = 0;
        int nextRangeEnd = 0;

        int jumps = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            nextRangeEnd = std::max(nextRangeEnd, i + nums[i]);

            if (i == currentRangeEnd) {
                jumps++;
                currentRangeEnd = nextRangeEnd;
            }
        }

        return jumps;
    }
};