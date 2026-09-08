class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle[triangle.size()-1].size(),0);
        dp[0]=triangle[0][0];
        int mini=INT_MAX;
        for(int i=0;i<triangle.size();i++){
            vector<int> temp(triangle[triangle.size()-1].size(),0);
            for(int j=0;j<triangle[i].size();j++){
                int curr=INT_MAX;
                int bef=INT_MAX;
                if(i==0 && j==0){
                    temp[j]=triangle[i][j];
                    continue;
                } 
                if(i>0 && j>0) bef=dp[j-1];
                if(i>0 && j<triangle[i-1].size()) curr=dp[j];
                temp[j]=triangle[i][j]+min(curr,bef);
            }
            dp=temp;
        }
        for(int i=0;i<triangle[triangle.size()-1].size();i++){
            mini=min(dp[i],mini);
        }
        return mini;
    }
};