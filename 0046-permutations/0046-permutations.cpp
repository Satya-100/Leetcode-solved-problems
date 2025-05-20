class Solution {
    void helper(vector<int>& freq, vector<int>& nums, vector<int>& ds, vector<vector<int>>& res){
        int n = nums.size();
        if(ds.size() == n){
            res.push_back(ds);
            return ;
        }

        for(int i=0;i<n;i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                helper(freq, nums, ds, res);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        int n = nums.size();
        vector<int> freq(n, 0);
        helper(freq, nums, ds, res);
        return res;
    }
};