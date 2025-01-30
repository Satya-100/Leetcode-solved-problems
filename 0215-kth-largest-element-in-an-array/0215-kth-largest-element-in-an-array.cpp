class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> hp;
        for(int i: nums){
            hp.push(i);
        }
        int res;
        while(k--){
            res=hp.top();
            hp.pop();
        }
        return res;
    }
};