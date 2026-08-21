class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<pair<int,int>>> adj(grid.size()*grid.size());
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid.size()){
                        adj[i+grid.size()*j].push_back({ni+grid.size()*nj,grid[ni][nj]});
                    }
                }
            }
        }
        vector<int> dist(grid.size()*grid.size(),INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[0]=grid[0][0];
        pq.push({dist[0],0});
        while(!pq.empty()){
            pair<int,int> temp=pq.top();
            pq.pop();
            int node=temp.second;
            int dis=temp.first;
            for(int i=0;i<adj[node].size();i++){
                int disi=max(adj[node][i].second,dis);
                if(dist[adj[node][i].first]>disi){
                    dist[adj[node][i].first]=disi;
                    pq.push({disi,adj[node][i].first});
                }
            }
        }
        return dist[grid.size()*grid.size()-1];
    }
};