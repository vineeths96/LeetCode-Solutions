class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int currentIndex = 0;
        int indexWithoutVal = 0;

        while (currentIndex < nums.size()) {
            if (nums[currentIndex] != val) {
                nums[indexWithoutVal] = nums[currentIndex];
                indexWithoutVal++;
            }

            currentIndex++;
        }

        return indexWithoutVal;
    }
};