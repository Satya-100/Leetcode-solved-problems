class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // int n=prerequisites.size();
        vector<int> indeg(numCourses, 0);
        unordered_map<int, vector<int>> graph;
        for(auto it: prerequisites){
            int u=it[0];
            int v=it[1];
            graph[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0) q.push(i);
        }

        if(q.size()==0) return false;

        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it: graph[node]){
                indeg[it]--;
                if(indeg[it]==0)    q.push(it);
            }
        }
        return cnt==graph.size()?true:false;
    }
};