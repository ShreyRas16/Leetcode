class Solution {
public:
    bool f(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(j==0) return true;
        if(i<0 || j<0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool take=f(i-1,j-nums[i],nums,dp);
        bool nottake=f(i-1,j,nums,dp);
        return dp[i][j]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum=sum+nums[i];
        if(sum%2!=0) return false;
        vector<vector<int>> dp(nums.size(),vector<int>((sum/2)+1,-1));
        return f(nums.size()-1,sum/2,nums,dp);
    }
};