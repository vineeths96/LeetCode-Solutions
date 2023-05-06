class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int arrayCount = 0;
        int product = 1;

        for (int left = 0, right = 0; right < nums.size(); right++) {
            product = product * nums[right];

            while (left <= right && product >= k) {
                product = product / nums[left];
                left++;
            }

            arrayCount += right - left + 1;
        }

        return arrayCount;
    }
};