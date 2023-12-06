class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nextLastNonZero = 0;
        int currentIndex = 0;

        while (currentIndex < nums.size()) {
            if (nums[currentIndex] != 0)
                std::swap(nums[nextLastNonZero++], nums[currentIndex]);
                
            currentIndex++;
        }
    }
};