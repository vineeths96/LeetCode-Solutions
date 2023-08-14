class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int start = 0;
        int end = nums.size();

        while (start < end) {
            if (nums[start] <= 0) {
                end--;
                std::swap(nums[start], nums[end]);
            } else
                start++;
        }

        for (int start = 0; start < end; start++) {
            if (nums[start] - 1 < end) {
                int newIndex = std::abs(nums[start]) - 1;
                if (nums[newIndex] > 0)
                    nums[newIndex] *= -1;
            }
        }

        for (int i = 0; i < end; i++) {
            if (nums[i] > 0)
                return i + 1;
        }

        return end + 1;
    }
};