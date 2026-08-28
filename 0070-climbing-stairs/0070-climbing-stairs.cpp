class Solution {
public:
    int find(vector<int>& dp,int n){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=find(dp,n-1)+find(dp,n-2);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return find(dp,n);
    }
};