class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        int mini = 0;
        int maxi = 0;
        int cur = 0;
        for(int i=0;i<n;i++){
            cur += differences[i];

            mini = min(mini, cur);
            maxi = max(maxi, cur);

            if((upper-lower+mini-maxi+1)<=0)    return 0;
        }
        return (upper-lower+mini-maxi+1);
    }
};

/*
[1,-3,4]

3 4 1 5
4 5 2 6

[3,-4,5,1,-2]  -4 ---> 5

-4 -1 -5  xxxxx
-3 0 -4 1 2 0
-2 1 -3 2 3 1
-1 2 -2 3 4 2
0 3 -1 4 5 3
1 4 0 5 6  xxxxxxxx

*/