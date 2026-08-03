class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) q.push({i,j,0});
            }
        }
        int ans=0;
        while(!q.empty()){
            vector<int> temp=q.front();
            q.pop();
            int x=q.size();
            if(temp[0]+1<grid.size() && grid[temp[0]+1][temp[1]]==1){
                grid[temp[0]+1][temp[1]]=2;
                q.push({temp[0]+1,temp[1],temp[2]+1});
            }
            if(temp[0]-1>=0 && grid[temp[0]-1][temp[1]]==1){
                grid[temp[0]-1][temp[1]]=2;
                q.push({temp[0]-1,temp[1],temp[2]+1});
            }
            if(temp[1]+1<grid[0].size() && grid[temp[0]][temp[1]+1]==1){
                grid[temp[0]][temp[1]+1]=2;
                q.push({temp[0],temp[1]+1,temp[2]+1});
            }
            if(temp[1]-1>=0 && grid[temp[0]][temp[1]-1]==1){
                grid[temp[0]][temp[1]-1]=2;
                q.push({temp[0],temp[1]-1,temp[2]+1});
            }
            if(q.size()==x) ans=max(ans,temp[2]);
        }
        bool found=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) found=true;
            }
        }
        if(found) return -1;
        else return ans;
    }
};