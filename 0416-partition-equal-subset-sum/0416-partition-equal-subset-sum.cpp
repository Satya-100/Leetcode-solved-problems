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
        int target=sum/2;
        if(sum%2!=0)    return false;
        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        // return f(n-1, target, nums, dp);

        for(int i=0;i<n;i++)    dp[i][0]=true;
        if(nums[0]<=target)  dp[0][nums[0]]=true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool notTaken = dp[i-1][j];
                bool taken=false;
                if(nums[i]<=j)  taken = dp[i-1][j-nums[i]];
                dp[i][j]=taken||notTaken;
            }
        }
        return dp[n-1][target];
    }
};