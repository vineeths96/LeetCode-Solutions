class Solution {
public:
    void searchPair(std::vector<int> nums, int index, std::vector<std::vector<int>> &triplets) {
        int start = index + 1;
        int end = nums.size() - 1;
        int targetSum = -nums[index];

        while (start < end) {
            int currentSum = nums[start] + nums[end];
            if (currentSum > targetSum)
                end--;
            else if (currentSum < targetSum)
                start++;
            else {
                triplets.push_back({nums[index], nums[start], nums[end]});
                start++;
                end--;

                while (start < end && nums[start] == nums[start-1]) 
                    start++;
                
                while (start < end && nums[end] == nums[end+1])
                    end--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> triplets;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            searchPair(nums, i, triplets);
        }

        return triplets;
    }
};