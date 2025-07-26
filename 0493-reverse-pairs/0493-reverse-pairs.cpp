class Solution {
    void merge(vector<int>& arr, int l, int mid, int r){
        int left = l;
        int right = mid+1;
        vector<int> temp;

        while(left<=mid && right<=r){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            } else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=r){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i=l;i<=r;i++){
            arr[i] = temp[i-l];
        }
    }

    int cntPairs(vector<int>& nums, int l, int mid, int r){
        int right = mid+1;
        int cnt = 0;
        for(int i=l;i<=mid;i++){
            while(right<=r && nums[i]>2ll*nums[right])    right++;
            cnt += (right-mid-1);
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int l, int r){
        int cnt = 0;
        if(l>=r)    return cnt;
        int mid = (l+r)/2;
        cnt += mergeSort(nums, l, mid);
        cnt += mergeSort(nums, mid+1, r);
        cnt += cntPairs(nums, l, mid, r);
        merge(nums, l, mid, r);
        return cnt;
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};