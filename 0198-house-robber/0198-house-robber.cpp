class Solution {
    int f(int ind, vector<int>& nums, vector<int>& dp){
        if(ind==0)  return nums[0];
        if(ind<0)   return 0;

        if(dp[ind]!=-1) return dp[ind];

        int pick = nums[ind] + f(ind-2, nums, dp);
        int notpick = f(ind-1, nums, dp);

        return dp[ind] = max(pick, notpick);
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n, 0);
        // dp[0] = nums[0];
        int prev2 = 0;
        int prev = nums[0];
        int curr;

        for(int i=1;i<n;i++){
            int take = nums[i] + prev2;
            int notTake = prev;

            curr = max(take, notTake);

            prev2 =  prev;
            prev = curr;
        }

        return prev;
    }
};