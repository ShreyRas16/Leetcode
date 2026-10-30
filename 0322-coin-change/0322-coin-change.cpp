class Solution {
public:
    int f(int i,int j,vector<int>& coins,vector<vector<int>>& dp){
        if(i<0){
            if(j==0) return 0;
            else return 1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int a=1e9;
        if(j>=coins[i]) a=1+f(i,j-coins[i],coins,dp);
        int b=f(i-1,j,coins,dp);
        return dp[i][j]=min(a,b);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=f(coins.size()-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        return f(coins.size()-1,amount,coins,dp);
    }
};