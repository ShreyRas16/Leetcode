class Solution {
public: 
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1){
                q.push({i,0});
                visited[i][0]=true;
            }
            if(grid[i][grid[0].size()-1]==1){
                q.push({i,grid[0].size()-1});
                visited[i][grid[0].size()-1]=true;
            }
        }
        for(int j=0;j<grid[0].size();j++){
            if(grid[0][j]==1){
                q.push({0,j});
                visited[0][j]=true;
            }
            if(grid[grid.size()-1][j]==1){
                q.push({grid.size()-1,j});
                visited[grid.size()-1][j]=true;
            }
        }
        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            pair<int,int> temp=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=temp.first+dr[k];
                int nc=temp.second+dc[k];
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==1 && !visited[nr][nc]){
                    q.push({nr,nc});
                    visited[nr][nc]=true;
                }
            }
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !visited[i][j]) count++;
            }
        }
        return count;
    }
};