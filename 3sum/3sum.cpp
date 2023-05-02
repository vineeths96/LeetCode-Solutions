class Solution {
public:
    void searchPair(std::vector<int> nums, int targetSum, int index, std::vector<std::vector<int>> &triplets) {
        int start = index + 1;
        int end = nums.size() - 1;

        while(start < end) {
            int currentSum = nums[start] + nums[end];
            if (currentSum == targetSum) {
                triplets.push_back({nums[index], nums[start], nums[end]});
                start++;
                end--;

                while (start < end && nums[start] == nums[start-1])
                    start++;

                while (start < end && nums[end] == nums[end+1])
                    end--;
            } else if (currentSum > targetSum)
                end--;
            else
                start++;
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> triplets;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            while (i > 0 && i < nums.size() && nums[i] == nums[i-1])
                i++;

            if (i == nums.size()) break;

            searchPair(nums, -nums[i], i, triplets);
        }

        return triplets;
    }
};