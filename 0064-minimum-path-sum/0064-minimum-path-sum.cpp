class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dp(m,0);
        dp[0]=grid[0][0];
        for(int i=0;i<n;i++){
            vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    curr[j]=grid[i][j];
                    continue;
                }
                int up=INT_MAX;
                int left=INT_MAX;
                if(i>0) up=dp[j];
                if(j>0) left=curr[j-1];
                curr[j]=grid[i][j]+min(up,left);
            }
            dp=curr;
        }
        return dp[m-1];
    }
};