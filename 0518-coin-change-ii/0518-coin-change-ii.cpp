class Solution {
public:
    int f(int i,int j,vector<int>& coins,vector<vector<int>>& dp){
        if(i<0){
            if(j==0) return 1;
            else return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(j>=coins[i]) take=f(i,j-coins[i],coins,dp);
        int nottake=f(i-1,j,coins,dp);
        return dp[i][j]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return f(coins.size()-1,amount,coins,dp);
    }
};