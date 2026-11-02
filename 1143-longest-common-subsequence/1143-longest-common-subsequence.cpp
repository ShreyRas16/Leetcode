class Solution {
public:
    int f(int i,int j,string& text1,string& text2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(text1[i]==text2[j]) take=1+f(i-1,j-1,text1,text2,dp);
        int nottakei=f(i-1,j,text1,text2,dp);
        int nottakej=f(i,j-1,text1,text2,dp);
        return dp[i][j]=max({take,nottakei,nottakej});
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return f(text1.size()-1,text2.size()-1,text1,text2,dp);
    }
};