class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(), n=text2.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        vector<int> prev(n+1, 0), curr(n+1, 0);

        for(int idx1=1;idx1<=m;idx1++){
            for(int idx2=1;idx2<=n;idx2++){
                if(text1[idx1-1]==text2[idx2-1]){
                    curr[idx2] = 1+prev[idx2-1];
                }
                else{
                    curr[idx2]=max(prev[idx2], curr[idx2-1]);
                }
            }
            prev=curr;
        }
        return prev[n];
    }
};