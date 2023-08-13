class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int index = 0;
        while (index < nums.size()) {
            if (nums[index] != nums[nums[index] - 1])
                std::swap(nums[index], nums[nums[index] - 1]);
            else
                index++;
        }

        std::vector<int> duplicates;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1)
                duplicates.push_back(nums[i]);
        }

        return duplicates;
    }
};