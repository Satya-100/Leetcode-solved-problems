class Solution {
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph){
        color[node] = col;
        for(int it: graph[node]){
            if(color[it]==-1){
                if(!dfs(it, !col, color, graph))    return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }

    bool bfs(int node, int n, vector<int>& color, vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        color[node]=0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto it: graph[cur]){
                if(color[it]==-1){
                    color[it] = !color[cur];
                    q.push(it);
                }
                else if(color[it]==color[cur]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i, n, color, graph))    return false;
            }
        }
        return true;
    }
};