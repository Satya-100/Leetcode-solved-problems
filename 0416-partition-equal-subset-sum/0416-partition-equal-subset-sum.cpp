class Solution {
    bool f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target==0)   return true;
        if(ind==0)  return target==nums[ind];

        if(dp[ind][target]!=-1) return dp[ind][target];

        bool notTaken = f(ind-1, target, nums, dp);
        bool taken = false;
        if(nums[ind]<=target)   taken = f(ind-1, target-nums[ind], nums, dp);
        return dp[ind][target] = (taken || notTaken);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i: nums)    sum+=i;
        if(sum%2!=0)    return false;
        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
        return f(n-1, sum/2, nums, dp);
    }
};