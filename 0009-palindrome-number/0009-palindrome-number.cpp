#include <cmath>
class Solution {
public:
    bool isPalindrome(int x) {
        long long k=x;
        long long r = 0;
        if (x < 0)
            return false;
        else {
            // int k = x;
            while (k > 0) {
                long long rem=k%10;
                r = r*10 + rem;
                // i--;
                k /= 10;
            }
            if (x == r)
                return true;
            else
                return false;
        }
    }
};