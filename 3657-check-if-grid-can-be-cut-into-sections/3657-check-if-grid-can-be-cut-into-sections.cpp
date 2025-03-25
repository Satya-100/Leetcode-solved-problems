class Solution {
    bool checkCuts(int dim, vector<vector<int>> rectangles){
        int gapCount = 0;
        sort(rectangles.begin(), rectangles.end(),
            [dim](vector<int>& a, vector<int>& b){
                return a[dim]<b[dim];
            });
        int furthestEnd = rectangles[0][dim+2];
        int n = rectangles.size();
        for(int i=1;i<n;i++){
            int start = rectangles[i][dim];
            if(start>=furthestEnd){
                gapCount++;
            }
            furthestEnd = max(furthestEnd, rectangles[i][dim+2]);
        }
        return gapCount>=2;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return checkCuts(0, rectangles) | checkCuts(1, rectangles);
    }
};