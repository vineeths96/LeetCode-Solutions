class Solution {
public:
    void sortColors(vector<int>& nums) {
        int current = 0;
        int firstTwoIndex = nums.size() - 1;
        int lastZeroIndex = 0;

        while (current <= firstTwoIndex) {
            if (nums[current] == 2) {
                std::swap(nums[current], nums[firstTwoIndex]);
                firstTwoIndex--;
            } else if (nums[current] == 0) {
                std::swap(nums[current], nums[lastZeroIndex]);
                current++;
                lastZeroIndex++;
            } else
                current++;
        }
    }
};