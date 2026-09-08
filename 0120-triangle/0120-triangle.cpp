class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),0));
        dp[0][0]=triangle[0][0];
        int mini=INT_MAX;
        for(int i=0;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                int curr=INT_MAX;
                int bef=INT_MAX;
                if(i==0 && j==0) continue;
                if(i>0 && j>0) bef=dp[i-1][j-1];
                if(i>0 && j<triangle[i-1].size()) curr=dp[i-1][j];
                dp[i][j]=triangle[i][j]+min(curr,bef);
            }
        }
        for(int i=0;i<triangle[triangle.size()-1].size();i++){
            mini=min(dp[triangle.size()-1][i],mini);
        }
        return mini;
    }
};