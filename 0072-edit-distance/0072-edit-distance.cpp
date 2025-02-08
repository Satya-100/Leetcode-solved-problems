class Solution {
    int f(string word1, int i, string word2, int j, vector<vector<int>>& dp){
        if(i<0)    return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(word1[i]==word2[j]){
            return dp[i][j]=f(word1, i-1, word2, j-1, dp);
        }
        else{
            return dp[i][j] = 1 + min(f(word1, i-1, word2, j-1, dp), 
                min(f(word1, i-1, word2, j, dp), f(word1, i, word2, j-1, dp)));
        }
    }

public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=i;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }

        return dp[m][n];
    }
};