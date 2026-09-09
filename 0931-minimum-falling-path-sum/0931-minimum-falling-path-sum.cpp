class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++) dp[i]=matrix[0][i];
        for(int i=1;i<n;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                int curr=dp[j];
                int left=INT_MAX;
                int right=INT_MAX;
                if(j>0) left=dp[j-1];
                if(j<n-1) right=dp[j+1];
                temp[j]=matrix[i][j]+min(curr,min(left,right));
            }
            dp=temp;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[i]);
        }
        return mini;
    }
};