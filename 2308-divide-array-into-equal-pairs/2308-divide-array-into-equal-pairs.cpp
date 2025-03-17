class Solution {
public:
    bool divideArray(vector<int>& nums) {
        set<int> st;
        for(int i: nums){
            if(st.find(i)!=st.end()){
                st.erase(i);
            }
            else{
                st.insert(i);
            }
        }
        return st.empty();
    }
};