class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        int carry = 0;
        int index = 0;
        
        while (index < sizeof(int) * CHAR_BIT && (a || b || carry)) {
            int bitSum = (a & 1) ^ (b & 1) ^ (carry & 1);
            carry = (a & 1) & (b & 1) | (a & 1) & (carry & 1) | (b & 1) & (carry & 1);
            sum = sum | (bitSum << index);

            a = a >> 1;
            b = b >> 1;
            index++;
        }

        return sum;
    }
};