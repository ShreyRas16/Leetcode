class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        for(int i=0;i<times.size();i++) adj[times[i][0]].push_back({times[i][1],times[i][2]});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int> temp=pq.top();
            pq.pop();
            int time=temp.first;
            int node=temp.second;
            if(time>dist[node]) continue;
            for(int i=0;i<adj[node].size();i++){
                int curr=adj[node][i].second;
                if(dist[adj[node][i].first]>time+curr){
                    dist[adj[node][i].first]=time+curr;
                    pq.push({dist[adj[node][i].first],adj[node][i].first});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            else ans=max(dist[i],ans);
        }
        return ans;
    }
};