class Solution {
public:
    void dfs(int u,int paru,vector<int>& dt,vector<int>& low,vector<int>& visited,vector<vector<int>>& adj,int& time,vector<vector<int>>& ans){
        visited[u]=1;
        low[u]=time;
        dt[u]=time;
        time++;
        for(int i=0;i<adj[u].size();i++){
            if(visited[adj[u][i]]==0){
                dfs(adj[u][i],u,dt,low,visited,adj,time,ans);
                low[u]=min(low[u],low[adj[u][i]]);
                if(low[adj[u][i]]>dt[u]) ans.push_back({u,adj[u][i]});
            }
            else{
                if(adj[u][i]!=paru){
                    low[u]=min(low[u],low[adj[u][i]]);
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<int> dt(n);
        vector<int> low(n);
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);
        int time=0;
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        dfs(0,-1,dt,low,visited,adj,time,ans);
        return ans;
    }
};