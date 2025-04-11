class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp = x;
        long k=0;
        while(temp>0){
            k = (k*10) + (temp%10);
            temp/=10;
        }
        return k==x;
    }
};