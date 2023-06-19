class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        std::stack<int> leftTracker;
        int leftBoundary = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++) {
            while (!leftTracker.empty() && nums[leftTracker.top()] > nums[i]) {
                leftBoundary = std::min(leftBoundary, leftTracker.top());
                leftTracker.pop();
            }

            leftTracker.push(i);
        }

        std::stack<int> rightTracker;
        int rightBoundary = 0;

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!rightTracker.empty() && nums[rightTracker.top()] < nums[i]) {
                rightBoundary = std::max(rightBoundary, rightTracker.top());
                rightTracker.pop();
            }

            rightTracker.push(i);
        }

        return rightBoundary - leftBoundary > 0 ? rightBoundary - leftBoundary + 1 : 0;
    }
};