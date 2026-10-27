class Solution {
public:
    int f(int i,int j1,int j2,vector<vector<vector<int>>>& dp,vector<vector<int>>& grid){
        if(i<0 || j1<0 || j2<0 || j1>grid[0].size()-1 || j2>grid[0].size()-1) return -1e9;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        if(i==0){
            if(j1!=0 || j2!=grid[0].size()-1) return dp[i][j1][j2]=-1e9;
            else return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
        }
        int def=max({f(i-1,j1,j2,dp,grid),f(i-1,j1,j2-1,dp,grid),f(i-1,j1,j2+1,dp,grid),f(i-1,j1-1,j2,dp,grid),f(i-1,j1-1,j2-1,dp,grid),f(i-1,j1-1,j2+1,dp,grid),f(i-1,j1+1,j2-1,dp,grid),f(i-1,j1+1,j2,dp,grid),f(i-1,j1+1,j2+1,dp,grid)});
        if(j1==j2) def=def+grid[i][j1];
        else def=def+grid[i][j1]+grid[i][j2];
        return dp[i][j1][j2]=def;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        int maxi=INT_MIN;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid[0].size();j++){
                maxi=max(maxi,f(grid.size()-1,i,j,dp,grid));
            }
        }
        return maxi;
    }
};