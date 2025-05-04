class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        vector<int> cnt(100, 0);
        int n = dominoes.size();
        for(auto it: dominoes){
            int val = it[0]<it[1] ? (it[0]*10 + it[1]) : (it[1]*10 + it[0]);
            res += cnt[val];
            cnt[val]++;
        }
        return res;
    }
};