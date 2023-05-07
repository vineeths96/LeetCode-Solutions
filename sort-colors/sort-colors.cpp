class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int lastZeroIndex = 0;

        while (start <= end) {
            if (nums[start] == 2) {
                std::swap(nums[start], nums[end]);
                end--;
            } else if (nums[start] == 0) {
                std::swap(nums[start], nums[lastZeroIndex]);
                start++;
                lastZeroIndex++;
            } else
                start++;
        }
    }
};