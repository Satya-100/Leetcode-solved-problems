class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int element = heights[st.top()];
                st.pop();
                int nge = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, element*(nge-pse-1));
            }

            st.push(i);
        }

        while(!st.empty()){
            int element = heights[st.top()];
            st.pop();
            int nge = n;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, element*(nge-pse-1));
        }

        return maxArea;
    }
};