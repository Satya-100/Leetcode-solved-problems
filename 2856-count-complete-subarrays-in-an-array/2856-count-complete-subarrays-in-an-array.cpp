class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        unordered_set<int> st;
        for(int i: nums)    st.insert(i);

        int i = 0;
        int j = 0;
        unordered_map<int, int> mp;

        while(j<n){
            mp[nums[j]]++;
            while(mp.size() == st.size()){
                res += n-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }

        return res;
    }
};