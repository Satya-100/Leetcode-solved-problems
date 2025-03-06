class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long total = n * n;
        long long sum = 0;
        long long sqr_sum = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += grid[i][j];
                sqr_sum += (long long)grid[i][j] * grid[i][j];
            }
        }

        long long sum_diff = sum - (total*(total+1)/2);
        long long sqr_diff = sqr_sum - (total*(total+1)*(2*total+1)/6);

        int repeat = ((sqr_diff/sum_diff) + sum_diff)/2;
        int missing = ((sqr_diff/sum_diff) - sum_diff)/2;

        return {repeat, missing};
    }
};