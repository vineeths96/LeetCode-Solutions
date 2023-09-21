class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;

        int targetSum = sum / 2;
        std::vector<bool> dpVector(targetSum + 1, false);    
        dpVector[0] = true;

        for (int i = 1; i <= nums.size(); i++)
            for (int j = targetSum; j >= 0; j--)
                dpVector[j] = dpVector[j] || (nums[i-1] <= j ? dpVector[j - nums[i-1]] : 0);
       
        return dpVector[targetSum];
    }
};