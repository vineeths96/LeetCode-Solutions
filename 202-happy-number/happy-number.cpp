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
        int slowPointer = n;
        int fastPointer = n;

        do {
            slowPointer = sumOfSquares(slowPointer);
            fastPointer = sumOfSquares(sumOfSquares(fastPointer));
        } while (fastPointer != slowPointer);

        return fastPointer == 1;
    }
};