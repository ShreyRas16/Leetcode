class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> rev(graph.size());
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                rev[graph[i][j]].push_back(i);
            }
        }
        unordered_map<int,int> indegree;
        for(int i=0;i<rev.size();i++){
            for(int j=0;j<rev[i].size();j++){
                indegree[rev[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<rev.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            topo.push_back(temp);
            for(int i=0;i<rev[temp].size();i++){
                indegree[rev[temp][i]]--;
                if(indegree[rev[temp][i]]==0) q.push(rev[temp][i]);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};