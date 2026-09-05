class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j]=1;
                    continue;
                }
                if(i>0) curr[j]=curr[j]+dp[j];
                if(j>0) curr[j]=curr[j]+curr[j-1];
            }
            dp=curr;
        }
        return dp[n-1];
    }
};