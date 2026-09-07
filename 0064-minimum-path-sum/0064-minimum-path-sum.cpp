class Solution {
public:
    int path(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 && j==0) return dp[i][j]=grid[i][j];
        int up=INT_MAX;
        int left=INT_MAX;
        if(i>0) up=path(grid,dp,i-1,j);
        if(j>0) left=path(grid,dp,i,j-1);
        return dp[i][j]=grid[i][j]+min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return path(grid,dp,n-1,m-1);
    }
};