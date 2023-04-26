class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;

        int start = 1, end = x;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            long midSquare = (long) mid * mid;

            if (midSquare == x)
                return mid;
            else if (midSquare > x)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return end;
    }
};