class Solution {
    bool dfs(int node, int destination, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited){
        if(node == destination)   return true;
        visited.insert(node);
        for(int i: graph[node]){
            if(visited.find(i)==visited.end()){
                if(dfs(i, destination, graph, visited))    return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        unordered_set<int> visited;
        return dfs(source, destination, graph, visited);
    }
};