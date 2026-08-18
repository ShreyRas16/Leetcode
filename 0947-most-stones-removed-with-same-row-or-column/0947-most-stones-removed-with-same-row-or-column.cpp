class Solution {
public:
    class dist{
        vector<int> parent;
        public:
        dist(int n){
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int find(int node){
            if(parent[node]==node) return node;
            return parent[node]=find(parent[node]);
        }
        void uni(int i,int j){
            int pi=find(i);
            int pj=find(j);
            if(pi==pj) return;
            parent[pi]=pj;
        }
    };
    int removeStones(vector<vector<int>>& stones) {
        int rows=0;
        int cols=0;
        for(int i=0;i<stones.size();i++){
            rows=max(rows,stones[i][0]);
            cols=max(cols,stones[i][1]);
        }
        dist ds(rows+cols+2);
        unordered_map<int,int> mp;
        for(int i=0;i<stones.size();i++){
            int noder=stones[i][0];
            int nodec=stones[i][1]+rows+1;
            ds.uni(noder,nodec);
            mp[noder]=1;
            mp[nodec]=1;
        }
        int count=0;
        for(auto it : mp){
            if(ds.find(it.first)==it.first) count++;
        }
        return stones.size()-count;
    }
};