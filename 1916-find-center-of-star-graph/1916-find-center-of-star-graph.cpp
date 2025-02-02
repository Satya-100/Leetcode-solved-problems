class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> deg(n+2, 0);
        for(vector<int> i: edges){
            deg[i[0]]++;
            deg[i[1]]++;
        }
        for(int i=1;i<=n+1;i++){
            if(deg[i]==n)   return i;
        }
        return -1;
    }
};