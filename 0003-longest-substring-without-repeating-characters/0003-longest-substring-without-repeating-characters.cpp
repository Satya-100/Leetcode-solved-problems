class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char> st;
        int res=0;
        int start=0;

        for(int end=0;end<n;end++){
            while(st.find(s[end])!=st.end()){
                st.erase(s[start]);
                start++;
            }
            st.insert(s[end]);
            res = max(res, end-start+1);
        }
        return res; 
    }
};