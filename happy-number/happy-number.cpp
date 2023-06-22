class Solution {
public:
    bool isHappy(int n) {
        std::set<int> numbers;

        do {
            int sumOfSquares = 0;
            
            while (n) {
                sumOfSquares += std::pow(n % 10, 2);
                n = n / 10;
            }

            n = sumOfSquares;
        } while (numbers.insert(n).second);

        return n == 1;
    }
};