class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1 || obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1) return 0;
        vector<int> dp(obstacleGrid[0].size(),-1);
        dp[0]=1;
        for(int i=0;i<obstacleGrid.size();i++){
            vector<int> curr(obstacleGrid[0].size(),0);
            for(int j=0;j<obstacleGrid[0].size();j++){
                if(i==0 && j==0){
                    curr[j]=1;
                    continue;
                }
                if(obstacleGrid[i][j]==1) continue;
                if(i>0) curr[j]=curr[j]+dp[j];
                if(j>0) curr[j]=curr[j]+curr[j-1];
            }
            dp=curr;
        }
        return dp[dp.size()-1];
    }
};