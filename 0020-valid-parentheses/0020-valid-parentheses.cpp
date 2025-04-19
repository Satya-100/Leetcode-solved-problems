class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;

        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            } else{
                if(st.size()==0)    return false;
                else if(s[i]==')' && st.top()=='('){
                    st.pop();
                }
                else if(s[i]=='}' && st.top()=='{'){
                    st.pop();
                }
                else if(s[i]==']' && st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        return st.size()==0;
    }
};