class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        vector<int> lastPos(3, -1);
        int res = 0;

        for(int i=0;i<len;i++){
            lastPos[s[i] - 'a'] = i;
            res += 1 + min({lastPos[0], lastPos[1], lastPos[2]});
        }
        
        return res;
    }
};