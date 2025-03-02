class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long xorr = 0;
        for(int i=0;i<n;i++){
            xorr ^= nums[i];
        }

        long rightMost = (xorr & (xorr-1)) ^ xorr;
        int b1=0, b2=0;
        for(int i=0;i<n;i++){
            if(rightMost & nums[i]){
                b1 ^= nums[i];
            }
            else{
                b2 ^= nums[i];
            }
        }

        return {b1, b2};
    }
};