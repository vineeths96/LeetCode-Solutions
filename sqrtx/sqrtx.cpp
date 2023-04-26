class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;

        long long currentNum = 1;
        while(currentNum * currentNum <= x)
            currentNum = currentNum * 2;

        int prevNum = currentNum / 2;
        int lowerBound = prevNum;
        while (prevNum <= currentNum) {
            long long mid = (prevNum + currentNum ) / 2;

            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
                currentNum = mid - 1;
            else {
                    lowerBound = mid;
                    prevNum = mid + 1;
            }
        }

        return lowerBound;        
    }
};