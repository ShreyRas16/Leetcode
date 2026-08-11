class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==0 && grid.size()==1) return 1;
        if(grid[0][0]!=0 || grid[grid.size()-1][grid.size()-1]!=0) return -1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid.size(),false));
        visited[0][0]=true;
        while(!q.empty()){
            pair<pair<int,int>,int> temp=q.front();
            q.pop();
            int dx[]={-1,-1,-1,0,0,1,1,1};
            int dy[]={-1,0,1,-1,1,-1,0,1};
            for(int k=0;k<8;k++){
                int ni=temp.first.first+dx[k];
                int nj=temp.first.second+dy[k];
                if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid.size() && grid[ni][nj]==0 && !visited[ni][nj]){
                    if(ni==grid.size()-1 && nj==grid.size()-1) return temp.second+1;
                    visited[ni][nj]=true;
                    q.push({{ni,nj},temp.second+1});
                }
            }
        }
        return -1;
    }
};