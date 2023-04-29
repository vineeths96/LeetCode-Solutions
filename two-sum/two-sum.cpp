class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numTracker;

        for (int i = 0; i < nums.size(); i++) {
            if (numTracker.find(target - nums[i]) != numTracker.end())
                return {i, numTracker[target - nums[i]]};

            numTracker.insert({nums[i], i});
        }

        return {};
    }
};