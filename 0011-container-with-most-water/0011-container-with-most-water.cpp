class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int res=INT_MIN;
        int i=0, j=n-1;
        while(i<j){
            res = max(res, (j-i)*min(height[i], height[j]));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return res;
    }
};