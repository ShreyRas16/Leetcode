class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,src,0});
        while(!pq.empty()){
            vector<int> temp=pq.top();
            pq.pop();
            if(temp[1]==dst) return temp[0];
            if(temp[2]==k+1) continue;
            for(int i=0;i<adj[temp[1]].size();i++){
                if(dist[adj[temp[1]][i].first][temp[2]+1]>temp[0]+adj[temp[1]][i].second){
                    dist[adj[temp[1]][i].first][temp[2]+1]=temp[0]+adj[temp[1]][i].second;
                    pq.push({temp[0]+adj[temp[1]][i].second,adj[temp[1]][i].first,temp[2]+1});
                }
            }
        }
        return -1;
    }
};