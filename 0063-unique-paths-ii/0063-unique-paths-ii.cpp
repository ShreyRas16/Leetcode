class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1 || obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1) return 0;
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        dp[0][0]=1;
        for(int i=0;i<obstacleGrid.size();i++){
            for(int j=0;j<obstacleGrid[0].size();j++){
                if(i==0 && j==0) continue;
                dp[i][j]=0;
                if(obstacleGrid[i][j]==1) continue;
                if(i>0 && obstacleGrid[i-1][j]!=1) dp[i][j]=dp[i][j]+dp[i-1][j];
                if(j>0 && obstacleGrid[i][j-1]!=1) dp[i][j]=dp[i][j]+dp[i][j-1];
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};