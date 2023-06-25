class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int slowPointer = i;
            int fastPointer = i;

            bool isForward = nums[i] > 0;
            bool isWrongDirection = false;
            do {
                if (nums[slowPointer] > 0 != isForward) {
                    isWrongDirection = true;
                    break;
                }
                slowPointer = (nums.size() + slowPointer + nums[slowPointer]) % nums.size();

                if (nums[fastPointer] > 0 != isForward) {
                    isWrongDirection = true;
                    break;
                } 
                fastPointer = (nums.size() + fastPointer + nums[fastPointer]) % nums.size();

                if (nums[fastPointer] > 0 != isForward) {
                    isWrongDirection = true;
                    break;
                } 
                fastPointer = (nums.size() + fastPointer + nums[fastPointer]) % nums.size();
            } while (slowPointer != fastPointer);
         
            if (isWrongDirection)
                continue;

            int loopLength = 0;
            do {
                slowPointer = (nums.size() + slowPointer + nums[slowPointer]) % nums.size();
                loopLength++;
            } while (slowPointer != fastPointer);

            if (loopLength > 1)
                return true;
        }

        return false;
    }
};