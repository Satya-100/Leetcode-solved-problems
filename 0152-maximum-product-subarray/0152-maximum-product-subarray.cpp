class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int n=nums.size();
        int prod1=nums[0], prod2=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0)   swap(prod1, prod2);
            prod1 = max(nums[i], prod1*nums[i]);
            prod2 = min(nums[i], prod2*nums[i]);
            res=max(res, prod1);
        }
        return res;
    }
};

