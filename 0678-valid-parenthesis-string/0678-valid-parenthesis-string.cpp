class Solution {
    bool f(string s, int ind, int cnt, vector<vector<int>>& dp){
        if(cnt<0)   return false;
        if(ind==s.size())   return cnt==0;
        if(dp[ind][cnt]!=-1)    return dp[ind][cnt];
        if(s[ind]=='(') return f(s, ind+1, cnt+1, dp);
        if(s[ind]==')') return f(s, ind+1, cnt-1, dp);
        return dp[ind][cnt] = f(s, ind+1, cnt+1, dp) || f(s, ind+1, cnt-1, dp) || f(s, ind+1, cnt, dp);
    }

public:
    bool checkValidString(string s) {
        int n=s.size();
        // vector<vector<int>> dp(n, vector<int>(n,-1));
        // return f(s, 0, 0, dp);
        int min=0, max=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]==')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(min<0)   min=0;
            if(max<0)   return false;
        }
        return min==0;
    }
};