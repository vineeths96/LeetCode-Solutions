class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowPointer = nums[0];
        int fastPointer = nums[0];

        do {
            slowPointer = nums[slowPointer];
            fastPointer = nums[nums[fastPointer]];
        } while (slowPointer != fastPointer);

        fastPointer = nums[0];
        while (slowPointer != fastPointer) {
            slowPointer = nums[slowPointer];
            fastPointer = nums[fastPointer];
        }

        return slowPointer;
    }
};