class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(adj.size(),false);
        int ans=0;
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                ans++;
                visited[i]=true;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(int j:adj[x]){
                        if(!visited[j]){
                            visited[j]=true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};