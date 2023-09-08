class Solution {
    int binarySearch(std::vector<int> nums, int target, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > target)
                end = mid - 1;
            else if (nums[mid] < target)
                start = mid + 1;
            else
                return mid;
        }

        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums.front() <= nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }

        int leftSearch = binarySearch(nums, target, 0, left);
        if (leftSearch != -1) return leftSearch;
        int rightSearch = binarySearch(nums, target, left, nums.size() - 1);
        if (rightSearch != -1) return rightSearch;

        return -1;
    }
};