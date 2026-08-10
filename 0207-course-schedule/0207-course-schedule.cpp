class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,int> indegree;
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++) indegree[adj[i][j]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            topo.push_back(temp);
            for(int i=0;i<adj[temp].size();i++){
                indegree[adj[temp][i]]--;
                if(indegree[adj[temp][i]]==0) q.push(adj[temp][i]);
            }
        }
        if(topo.size()!=numCourses) return false;
        return true;
    }
};