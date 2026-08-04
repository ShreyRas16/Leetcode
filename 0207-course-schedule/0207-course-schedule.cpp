class Solution {
public:
    bool check(int node,vector<vector<int>>& adj,vector<bool>& vis,vector<bool>& path){
        vis[node]=true;
        path[node]=true;
        for(int next:adj[node]){
            if(!vis[next]){
                if(check(next,adj,vis,path)) return true;
            }
            else if(path[next]) return true;
        }
        path[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> vis(numCourses);
        vector<bool> path(numCourses);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(check(i,adj,vis,path)) return false;
            }
        }
        return true;
    }
};