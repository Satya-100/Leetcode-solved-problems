class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal;
        int cnt=0;
        while(temp!=0){
            temp = temp & (temp-1);
            cnt++;
        }
        return cnt;
    }
};


/*
10 --> 1 0 1 0
7  --> 0 1 1 1
       x x   x
*/