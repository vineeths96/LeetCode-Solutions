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

        start = 0;
        while (start < end) {
            if (nums[start] > 0 && nums[start] < nums.size() && nums[start] != nums[nums[start] - 1])
                std::swap(nums[start], nums[nums[start] - 1]);
            else
                start++;
        }

        for (int i = 0; i < end; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return end + 1;
    }
};