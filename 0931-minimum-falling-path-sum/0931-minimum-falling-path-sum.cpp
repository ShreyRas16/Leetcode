class Solution {
public:
    int sum(vector<vector<int>>& matrix,vector<vector<int>>& dp,int n,int i,int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0) return dp[i][j]=matrix[i][j];
        int curr=sum(matrix,dp,n,i-1,j);
        int left=INT_MAX;
        int right=INT_MAX;
        if(j>0) left=sum(matrix,dp,n,i-1,j-1);
        if(j<n-1) right=sum(matrix,dp,n,i-1,j+1);
        return dp[i][j]=matrix[i][j]+min(curr,min(left,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++) dp[0][i]=matrix[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int curr=dp[i-1][j];
                int left=INT_MAX;
                int right=INT_MAX;
                if(j>0) left=dp[i-1][j-1];
                if(j<n-1) right=dp[i-1][j+1];
                dp[i][j]=matrix[i][j]+min(curr,min(left,right));
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
    }
};