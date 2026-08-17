class Solution {
public:
    class dis{
        vector<int> parent;
        public:
        dis(int n){
            parent.resize(n);
            for(int i=0;i<parent.size();i++){
                parent[i]=i;
            }
        }
        int find(int node){
            if(parent[node]==node) return node;
            return parent[node]=find(parent[node]);
        }
        void uni(int x,int y){
            int px=find(x);
            int py=find(y);
            if(px==py) return;
            parent[px]=py;
        }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        dis ds(n);
        for(int i=0;i<connections.size();i++){
            ds.uni(connections[i][0],connections[i][1]);
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(ds.find(i)==i) ans++;
        }
        return ans;
    }
};