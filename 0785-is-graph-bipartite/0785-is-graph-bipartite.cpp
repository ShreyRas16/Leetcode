class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(),false);
        unordered_map<int,int> mp;
        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                mp[i]=1;
                queue<int> q;
                q.push(i);
                visited[i]=true;
                while(!q.empty()){
                    int temp=q.front();
                    q.pop();
                    for(int i=0;i<graph[temp].size();i++){
                        if(!visited[graph[temp][i]]){
                            mp[graph[temp][i]]=mp[temp]*(-1);
                            visited[graph[temp][i]]=true;
                            q.push(graph[temp][i]);
                        }
                        else{
                            if(mp[graph[temp][i]]==mp[temp]*(-1)) continue;
                            else return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};