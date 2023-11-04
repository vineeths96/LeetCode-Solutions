class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dpVector(nums.size() , 1);
        
        int maxLength = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dpVector[i] = std::max(dpVector[i], 1 + dpVector[j]);
                
                maxLength = std::max(maxLength, dpVector[i]);
            }
        }
        return maxLength;
    }
};