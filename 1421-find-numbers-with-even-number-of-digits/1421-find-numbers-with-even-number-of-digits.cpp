class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(int i: nums){
            int dig = floor(log10(i)) + 1;
            if(dig%2==0)    res++;
        }
        return res;
    }
};