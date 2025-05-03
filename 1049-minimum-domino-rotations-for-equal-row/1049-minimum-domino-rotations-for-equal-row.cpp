class Solution {
    int find(vector<int>& tops, vector<int>& bottoms, int domino){
        int n = tops.size();
        int swapTop = 0;
        int swapBottom = 0;
        for(int i=0;i<n;i++){
            if(domino!=tops[i] && domino!=bottoms[i]){
                return -1;
            } else if(tops[i]!=domino){
                swapBottom++;
            } else if(bottoms[i]!=domino){
                swapTop++;
            }
        }
        return min(swapTop, swapBottom);
    }

public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = INT_MAX;

        for(int domino=1;domino<=6;domino++){
            int swaps = find(tops, bottoms, domino);

            if(swaps!=-1){
                res = min(res, swaps);
            }
        }

        return res==INT_MAX ? -1 : res;
    }
};