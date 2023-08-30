class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> subsets;
        subsets.push_back({});

        int previousSize = -1;
        for (int i = 0; i < nums.size(); i++) {
            int start = (i > 0 && nums[i] == nums[i-1]) ? previousSize : 0;
            previousSize = subsets.size();

            while (start < previousSize) {
                auto currentVector = subsets[start++];
                currentVector.push_back(nums[i]);
                subsets.push_back(currentVector);
            }
        }

        return subsets;
    }
};