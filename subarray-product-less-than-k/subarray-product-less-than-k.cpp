class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int subArrayCount = 0;

        for (int left = 0, right = 0; left < nums.size() && right < nums.size(); right++) {
            product = product * nums[right];

            while (left < nums.size() && product >= k)
                product = product / nums[left++];

            if (left <= right)
                subArrayCount += (right - left + 1);    
        }

        return subArrayCount;
    }
};