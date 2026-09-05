class Solution {
public:
    int ways(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 && j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int count=0;
        if(j>0) count=count+ways(i,j-1,m,n,dp);
        if(i>0) count=count+ways(i-1,j,m,n,dp);
        return dp[i][j]=count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return ways(m-1,n-1,m,n,dp);
    }
};