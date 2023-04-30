class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastUniqueIndex = 0;
        int currentIndex = 0;

        while(currentIndex < nums.size()) {
            if (currentIndex == 0) {
                lastUniqueIndex++;
                currentIndex++;
                continue;
            }

            if (nums[currentIndex] == nums[lastUniqueIndex - 1]) {
                currentIndex++;
                continue;
            }

            nums[lastUniqueIndex] = nums[currentIndex];
            lastUniqueIndex++;
            currentIndex++;
        }

        return lastUniqueIndex;
    }
};