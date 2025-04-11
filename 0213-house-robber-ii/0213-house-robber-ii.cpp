class Solution {
    int f(vector<int> nums){
        int n=nums.size();
        int prev2=0;
        int prev=nums[0];
        int curr;

        for(int i=1;i<n;i++){
            int take = nums[i] + prev2;
            int notTake = prev;

            curr = max(take, notTake);

            prev2=prev;
            prev=curr;
        }

        return prev;
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums[0];

        vector<int> arr1, arr2;
        for(int i=0;i<n-1;i++)  arr1.push_back(nums[i]);
        for(int i=1;i<n;i++)  arr2.push_back(nums[i]);

        return max(f(arr1), f(arr2));
    }
};