class Solution {
    int binarySearch(const std::vector<int> &nums, int target, bool startingSearch) {
        int left = 0;
        int right = nums.size() - 1;

        int index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target < nums[mid])
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else {
                index = mid;
                if (startingSearch)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }

        return index;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startingIndex = binarySearch(nums, target, true);
        int endingIndex = binarySearch(nums, target, false);
        
        return {startingIndex, endingIndex};
    }
};