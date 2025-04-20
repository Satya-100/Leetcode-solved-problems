class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(int i: answers){
            mp[i]++;
        }

        int res = 0;
        for(auto it: mp){
            res += ceil(it.second*1.0/(it.first+1)*1.0)*(it.first+1);
        }

        return res;
    }
};

/*
1 -> 2
2 -> 1

1*2 + 1*3
*/