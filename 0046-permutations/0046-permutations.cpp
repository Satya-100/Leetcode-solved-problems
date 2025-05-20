class Solution {
    void helper(int ind, vector<vector<int>>& res, vector<int>& nums){
        int n = nums.size();
        if(ind==n){
            res.push_back(nums);
            return ;
        }

        for(int i=ind;i<n;i++){
            swap(nums[i], nums[ind]);
            helper(ind+1, res, nums);
            swap(nums[i], nums[ind]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(0, res, nums);
        return res;
    }
};