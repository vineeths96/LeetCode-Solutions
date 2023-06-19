class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minSeen = std::numeric_limits<int>::max();
        int maxSeen = std::numeric_limits<int>::min();

        int rightBoundary = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxSeen = std::max(maxSeen, nums[i]);

            if (maxSeen > nums[i])
                rightBoundary = i;
        }

        int leftBoundary = 0;
        for (int i = nums.size() - 1; i >= 0 ; i--) {
            minSeen = std::min(minSeen, nums[i]);

            if (minSeen < nums[i])
                leftBoundary = i;
        }

        return rightBoundary - leftBoundary > 0 ? rightBoundary - leftBoundary + 1 : 0;
    }
};