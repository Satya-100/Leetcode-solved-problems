class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;

        long long zero1 = 0;
        long long zero2 = 0;

        for (int it : nums1) {
            sum1 += it == 0 ? 1 : it;
            zero1 += it == 0 ? 1 : 0;
        }

        for (int it : nums2) {
            sum2 += it == 0 ? 1 : it;
            zero2 += it == 0 ? 1 : 0;
        }

        if ((sum1 < sum2 && zero1 == 0) || (sum2 < sum1 && zero2 == 0))
            return -1;

        return max(sum1, sum2);
    }
};