class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int free=0;
        int latest=0;
        
        sort(meetings.begin(), meetings.end());

        for(auto i: meetings){
            int start=i[0];
            int end=i[1];

            if(start>latest+1){
                free += start-latest-1;
            }
            
            latest=max(latest, end);
        }

        free += days-latest;
        return free;
    }
};