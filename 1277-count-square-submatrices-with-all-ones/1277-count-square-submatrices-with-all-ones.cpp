class Solution {
public:
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>matrix.size()-1 || j>matrix[0].size()-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(matrix[i][j]==0) return dp[i][j]=0;
        return dp[i][j]=1+min({f(i-1,j,matrix,dp),f(i,j-1,matrix,dp),f(i-1,j-1,matrix,dp)});
    }
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int total=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1) total=total+f(i,j,matrix,dp);
            }
        }
        return total;
    }
};