class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int res = 0;

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i] + nums[j] < target){
        //             res++;
        //         }
        //     }
        // }

        sort(nums.begin(), nums.end());
        int left = 0, right = n-1;

        while(left<right){
            if(nums[left] + nums[right] < target){
                res+=right-left;
                left++;
            }

            else{
                right--;;
            }
        }

        return res;
    }
};

// -1 1 1 2 3