class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        unordered_set<char> st;
        int i=0;
        for(int j=0;j<n;j++){
            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            res = max(res, j-i+1);
        }
        return res;
    }
};