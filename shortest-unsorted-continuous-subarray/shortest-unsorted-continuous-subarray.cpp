class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        std::vector<int> minArray(nums.size(), 0);
        std::vector<int> maxArray(nums.size(), 0);

        maxArray[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            maxArray[i] = std::max(maxArray[i-1], nums[i]);

        minArray[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--)
            minArray[i] = std::min(minArray[i+1], nums[i]);

        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            if (nums[start] <= nums[start+1] && nums[start] <= minArray[start])
                start++;
            else
                break;
        }

        while (start < end) {
            if (nums[end] >= nums[end-1] && nums[end] >= maxArray[end])
                end--;
            else
                break;
        }
        
        return start == end ? 0 : end - start + 1;
    }
};