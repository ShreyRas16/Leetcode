class Solution {
public:
    class dist{
        vector<int> parent;
        public:
        dist(int n){
            parent.resize(n);
            for(int i=0;i<parent.size();i++) parent[i]=i;
        }
        int find(int i){
            if(parent[i]==i) return i;
            return parent[i]=find(parent[i]);
        }
        void uni(int i,int j){
            int pi=find(i);
            int pj=find(j);
            if(pi!=pj) parent[pj]=pi;
        }
    };
    int largestIsland(vector<vector<int>>& grid) {
        dist ds(grid.size()*grid.size());
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int ni=i+dx[k];
                        int nj=j+dy[k];
                        if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid.size() && grid[ni][nj]==1){
                            ds.uni(ni*grid.size()+nj,i*grid.size()+j);
                        } 
                    }
                }
            }
        }
        unordered_map<int,int> size;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1){
                    size[ds.find(i*grid.size()+j)]++;
                }
            }
        }
        int ans=0;
        bool found=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==0){
                    int curr=1;
                    unordered_map<int,bool> seen;
                    found=true;
                    for(int k=0;k<4;k++){
                        int ni=i+dx[k];
                        int nj=j+dy[k];
                        if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid.size() && grid[ni][nj]==1){
                            if(!seen[ds.find(ni*grid.size()+nj)]){
                                curr=curr+size[ds.find(ni*grid.size()+nj)];
                                seen[ds.find(ni*grid.size()+nj)]=true;
                            }
                        }
                    }
                    ans=max(ans,curr);
                }
            }
        }
        if(!found) return grid.size()*grid.size();
        return ans;
    }
};