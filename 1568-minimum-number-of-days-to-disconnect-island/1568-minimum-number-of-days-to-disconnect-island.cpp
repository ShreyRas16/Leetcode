class Solution {
public:
    void dfs(int u,int paru,vector<vector<int>>& adj,vector<int>& visited,vector<int>& dist,vector<int>& low,int& time,bool& found){
        if(found) return;
        visited[u]=1;
        dist[u]=time;
        low[u]=time;
        time++;
        int child=0;
        if(found) return;
        for(int i=0;i<adj[u].size();i++){
            if(adj[u][i]==paru) continue;
            if(visited[adj[u][i]]==0){
                dfs(adj[u][i],u,adj,visited,dist,low,time,found);
                low[u]=min(low[u],low[adj[u][i]]);
                if(low[adj[u][i]]>=dist[u] && paru!=-1) found=true;
                child++;
            }
            else{
                low[u]=min(low[u],low[adj[u][i]]);
            }
        }
        if(paru==-1 && child>1) found=true;
    }
    void df(int u,vector<int>& visi,vector<vector<int>>& adj){
        visi[u]=1;
        for(int i=0;i<adj[u].size();i++){
            if(visi[adj[u][i]]==0) df(adj[u][i],visi,adj);
        }
    }
    int minDays(vector<vector<int>>& grid) {
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        int lands=0;
        vector<vector<int>> adj(grid.size()*grid[0].size());
        vector<int> visited(grid.size()*grid[0].size(),0);
        vector<int> dist(grid.size()*grid[0].size());
        vector<int> low(grid.size()*grid[0].size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    lands++;
                    for(int k=0;k<4;k++){
                        int ni=i+dx[k];
                        int nj=j+dy[k];
                        if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && grid[ni][nj]==1){
                            adj[i*grid[0].size()+j].push_back(ni*grid[0].size()+nj);
                        }
                    }
                }
            }
        }
        if(lands==0) return 0;
        if(lands==1) return 1;
        int time=0;
        bool found=false;
        int count=0;
        vector<int> visi(grid.size()*grid[0].size());
        for(int i=0;i<adj.size();i++){
            int r = i / grid[0].size();
            int c = i % grid[0].size();
            if(grid[r][c] == 0) continue;
            if(visi[i]==0){
                count++;
                df(i,visi,adj);
            }
        }
        if(count>1) return 0;
        int start=-1;
        for(int i=0;i<adj.size();i++){
            if(!adj[i].empty()) start=i;
        }
        dfs(start,-1,adj,visited,dist,low,time,found);
        if(found) return 1;
        return 2;
    }
};