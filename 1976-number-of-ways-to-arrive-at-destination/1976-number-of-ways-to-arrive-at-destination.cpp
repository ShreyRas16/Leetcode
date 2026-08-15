class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long,long>>> adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);
        ways[0]=1;
        dist[0]=0;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        long long mod=1e9+7;
        while(!pq.empty()){
            pair<long long,long long> temp=pq.top();
            pq.pop();
            long long dis=temp.first;
            long long node=temp.second;
            for(int i=0;i<adj[node].size();i++){
                if(dist[adj[node][i].first]>dis+adj[node][i].second){
                    ways[adj[node][i].first]=ways[temp.second];
                    dist[adj[node][i].first]=dis+adj[node][i].second;
                    pq.push({dist[adj[node][i].first],adj[node][i].first});
                }
                else if(dist[adj[node][i].first]==dis+adj[node][i].second){
                    ways[adj[node][i].first]=(ways[adj[node][i].first]+ways[temp.second])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};