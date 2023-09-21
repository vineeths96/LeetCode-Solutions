class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;

        int targetSum = sum / 2;
        std::vector<std::vector<bool>> dpVector(nums.size() + 1, std::vector<bool>(targetSum + 1, false));
        for (int i = 0; i < dpVector.size(); i++)
            dpVector[i][0] = true;

        for (int j = 1; j < dpVector[0].size(); j++)
            dpVector[0][j] = false;

        for (int i = 1; i < dpVector.size(); i++)
            for (int j = 1; j < dpVector[0].size(); j++)
                dpVector[i][j] = dpVector[i-1][j] || (nums[i-1] <= j ? dpVector[i-1][j - nums[i-1]] : 0);
       
        return dpVector[nums.size()][targetSum];
    }
};