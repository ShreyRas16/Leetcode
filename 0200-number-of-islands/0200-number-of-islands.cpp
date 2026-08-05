class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(), false));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j]=true;
                    int dr[]={-1,1,0,0};
                    int dc[]={0,0,-1,1};
                    while(!q.empty()){
                        pair<int,int> temp=q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr=temp.first+dr[k];
                            int nc=temp.second+dc[k];
                            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='1' && !visited[nr][nc]){
                                visited[nr][nc]=true;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};