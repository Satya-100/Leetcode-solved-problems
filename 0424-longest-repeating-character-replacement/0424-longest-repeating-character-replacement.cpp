class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int res = 0;
        int max_f = 0;
        unordered_map<char, int> mp;
        int l = 0, r = 0;

        while(r < n){
            mp[s[r] - 'A']++;
            max_f = max(max_f, mp[s[r]-'A']);

            if((r-l+1) - max_f <= k){
                res = max(res, r-l+1);
            } else{
                mp[s[l]-'A']--;
                max_f = 0;
                l++;
            }

            r++;
        }

        return res;
    }
};