class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& visited){
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(visited[adj[node][i]]==0){
                dfs(adj[node][i],adj,visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> visited(n,0);
        int ans=-1;
        for(int i=0;i<adj.size();i++){
            if(visited[i]==0){
                ans++;
                dfs(i,adj,visited);
            }
        }
        return ans;
    }
};