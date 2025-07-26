class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        map<int, int> mp;
        for(int i: nums){
            if(i%2==0){
                mp[i]++;
            }
        }

        int cnt = 0;
        int res = -1;
        for(auto i: mp){
            if(i.second>cnt){
                cnt = i.second;
                res = i.first;
            }
        }

        return res;
    }
};