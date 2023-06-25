class Solution {
    int getNextIndex(std::vector<int> nums, int index, bool isForward) {
        if (index < 0 || nums[index] > 0 != isForward)
            return -1;

        return (nums.size() + index + nums[index]) % nums.size();
}

public:
    bool circularArrayLoop(vector<int>& nums) {
        std::vector<bool> visited(nums.size(), false);

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;

            int slowPointer = i;
            int fastPointer = i;
            visited[i] = true;

            bool isForward = nums[i] > 0;
            do {
                slowPointer = getNextIndex(nums, slowPointer, isForward);
                fastPointer = getNextIndex(nums, fastPointer, isForward);
                fastPointer = getNextIndex(nums, fastPointer, isForward);

                if (slowPointer == -1 || fastPointer == -1)
                    break;
                
                if (visited[slowPointer] || visited[fastPointer])
                    continue;
                else
                    visited[slowPointer] = visited[fastPointer] = true;
            } while (slowPointer != fastPointer);

            if (slowPointer == -1 || fastPointer == -1)
                continue;

            if (slowPointer != getNextIndex(nums, slowPointer, isForward))
                return true;
        }

        return false;
    }
};