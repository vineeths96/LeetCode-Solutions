class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int index = 0;

        while (index < nums.size()) {
            if (nums[index] != nums.size() && nums[index] != nums[nums[index]]) 
                std::swap(nums[index], nums[nums[index]]);
            else
                index++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i)
                return i;
        }

        return nums.size();
    }
};