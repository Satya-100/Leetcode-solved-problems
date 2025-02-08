class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(), n=text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }

        for(int idx1=1;idx1<=m;idx1++){
            for(int idx2=1;idx2<=n;idx2++){
                if(text1[idx1-1]==text2[idx2-1]){
                    dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                }
                else{
                    dp[idx1][idx2]=max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
                }
            }
        }
        return dp[m][n];
    }
};