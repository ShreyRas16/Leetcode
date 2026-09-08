class Solution {
public:
    int sum(vector<vector<int>>& triangle,vector<vector<int>>& dp,int i,int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 && j==0) return dp[i][j]=triangle[i][j];
        int curr=INT_MAX;
        int bef=INT_MAX;
        if(i>0 && j>0) bef=sum(triangle,dp,i-1,j-1);
        if(i>0 && j<triangle[i-1].size()) curr=sum(triangle,dp,i-1,j);
        return dp[i][j]=triangle[i][j]+min(bef,curr);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int mini=INT_MAX;
        for(int i=0;i<triangle[triangle.size()-1].size();i++){
            vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
            mini=min(mini,sum(triangle,dp,triangle[triangle.size()-1].size()-1,i));
        }
        return mini;
    }
};