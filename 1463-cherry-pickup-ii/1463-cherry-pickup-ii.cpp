class Solution {
public:
    int f(int i,int j,int k,vector<vector<vector<int>>>& dp,vector<vector<int>>& grid){
        if(i<0 || j<0 || k<0 || i>grid.size()-1 || j>grid[0].size()-1 || k>grid[0].size()-1) return -1e9;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(i==0 && (j!=0 || k!=grid[0].size()-1)) return dp[i][j][k]=-1e9;
        int total=0;
        if(j==k) total=grid[i][j];
        else total=grid[i][j]+grid[i][k];
        return dp[i][j][k]=total+max({f(i-1,j-1,k-1,dp,grid),f(i-1,j-1,k,dp,grid),f(i-1,j-1,k+1,dp,grid),f(i-1,j,k-1,dp,grid),f(i-1,j,k,dp,grid),f(i-1,j,k+1,dp,grid),f(i-1,j+1,k-1,dp,grid),f(i-1,j+1,k,dp,grid),f(i-1,j+1,k+1,dp,grid)});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        dp[0][0][grid[0].size()-1]=grid[0][0]+grid[0][grid[0].size()-1];
        int ans=INT_MIN;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans=max(ans,f(grid.size()-1,i,j,dp,grid));
            }
        }
        return ans;
    }
};