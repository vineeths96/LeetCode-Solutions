class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastUniqueIndex = 1;
        int currentIndex = 1;

        while(currentIndex < nums.size()) {
            if (nums[currentIndex] != nums[lastUniqueIndex - 1]) {
                nums[lastUniqueIndex] = nums[currentIndex];
                lastUniqueIndex++;
            }

            currentIndex++;
        }

        return lastUniqueIndex;
    }
};