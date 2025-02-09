class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int size=cuts.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        
        for(int len=2;len<size;len++){
            for(int i=0;i<size-len;i++){
                int j=i+len;
                dp[i][j]=INT_MAX;
                for(int k=i+1;k<j;k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j]-cuts[i]);
                }
            }
        }
        return dp[0][size-1];
    }
};