class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i: nums)    pq.push(i);
        int cnt=0;
        while(pq.top()<k){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            long long temp = x*2 + y;
            pq.push(temp);
            cnt++;
        }
        return cnt;
    }
};