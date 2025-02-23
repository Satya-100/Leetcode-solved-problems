class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[1]<b[1];});
        // for(auto it: intervals){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        int n=intervals.size();
        int cnt=0;
        int freeTime=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=freeTime){
                freeTime = intervals[i][1];
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};