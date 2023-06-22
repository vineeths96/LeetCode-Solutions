class Solution {
private:
    int sumOfSquares(int n) {
        int sum = 0;

        while (n) {
            sum += std::pow(n % 10, 2);
            n = n / 10;
        }

        return sum;
    }

public:
    bool isHappy(int n) {
        int slowPointer = sumOfSquares(n);
        int fastPointer = sumOfSquares(sumOfSquares(n));

        while (fastPointer != slowPointer) {
            slowPointer = sumOfSquares(slowPointer);
            fastPointer = sumOfSquares(sumOfSquares(fastPointer));
        }

        return fastPointer == 1;
    }
};