class Solution {
    int f(vector<int> coins, int amount, int i, vector<vector<int>>& dp){
        if(amount==0)   return 0;
        if(i==0) return (amount%coins[0]==0)?amount/coins[0]:1e9;
        if(dp[i][amount]!=-1)   return dp[i][amount];
        int notTake = f(coins, amount, i-1, dp);
        int take=1e9;
        if(coins[i]<=amount)    take = 1+f(coins, amount-coins[i], i, dp);
        return dp[i][amount] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int res=f(coins, amount, n-1, dp);
        return res==1e9?-1:res;
    }
};