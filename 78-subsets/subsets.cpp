class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> powerSet;
        for (int i = 0; i < std::pow(2, nums.size()); i++) {
            std::vector<int> currentVector;
            for (int j = 0, mask = i; j < nums.size(); j++, mask = mask >> 1)
                if (mask & 1) currentVector.push_back(nums[j]);
            
            powerSet.push_back(currentVector);
        }

        return powerSet;
    }
};