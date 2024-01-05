class Solution {
public:
    double myPow(double x, int n) {
        double answer = 1;
        long long nDash = n;
        if (nDash < 0) {
            x = 1.0 / x;
            nDash = -nDash;
        }

        while (nDash) {
            if (nDash & 1) answer = answer * x;
            x = x * x; 
            nDash = nDash >> 1;
        }

        return answer;
    }
};