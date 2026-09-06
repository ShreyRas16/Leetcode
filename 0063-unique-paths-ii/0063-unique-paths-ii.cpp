class Solution {
public:
    int paths(vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp,int i,int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 && j==0) return dp[i][j]=1;
        if(obstacleGrid[i][j]==1) return dp[i][j]==0;
        int up=0;
        int left=0;
        if(i>0) up=paths(obstacleGrid,dp,i-1,j);
        if(j>0) left=paths(obstacleGrid,dp,i,j-1);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        if(obstacleGrid[0][0]==1 || obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1) return 0;
        return paths(obstacleGrid,dp,obstacleGrid.size()-1,obstacleGrid[0].size()-1);
    }
};