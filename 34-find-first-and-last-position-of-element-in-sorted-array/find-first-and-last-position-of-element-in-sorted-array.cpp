class Solution {
    int binarySearch(const std::vector<int> &nums, int target, bool startingSearch) {
        int left = 0;
        int right = nums.size() - 1;

        int index = startingSearch ? nums.size() : -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) 
                index = startingSearch ? std::min(index, mid) : std::max(index, mid);
            
            if (startingSearch) {
                if (nums[mid] >= target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else {
                if (nums[mid] <= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return index == nums.size() ? -1 : index;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startingIndex = binarySearch(nums, target, true);
        int endingIndex = binarySearch(nums, target, false);
        
        return {startingIndex, endingIndex};
    }
};