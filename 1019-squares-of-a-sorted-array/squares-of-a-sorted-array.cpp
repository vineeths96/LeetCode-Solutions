class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start = 0; 
        int end = nums.size() - 1;

        std::vector<int> output(nums.size(), 0);
        int outputIndex = nums.size() - 1;

        while(start <= end) {
            int startSquare = nums[start] * nums[start];
            int endSquare = nums[end] * nums[end];

            if (startSquare < endSquare) {
                output[outputIndex] = endSquare;
                end--;        
            } else {
                output[outputIndex] = startSquare;
                start++;
            }

            outputIndex--;
        }

        return output;
    }
};