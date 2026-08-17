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
        dist ds(stones.size());
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]) ds.uni(i,j);
            }
        }
        int count=0;
        for(int i=0;i<stones.size();i++){
            if(ds.find(i)==i) count++;
        }
        return stones.size()-count;
    }
};