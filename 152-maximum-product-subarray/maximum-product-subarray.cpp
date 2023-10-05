class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int maxCurrent = nums[0];
        int minCurrent = nums[0];
        int maxProduct = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int maxCurrentHolder = std::max(nums[i], std::max(maxCurrent * nums[i], minCurrent * nums[i]));
            minCurrent = std::min(nums[i], std::min(minCurrent * nums[i], maxCurrent * nums[i]));
            maxCurrent = maxCurrentHolder; 

            maxProduct = std::max(maxProduct, maxCurrent);
        }
        
        return maxProduct;
    }
};