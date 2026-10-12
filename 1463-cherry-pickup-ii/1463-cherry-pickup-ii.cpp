class Solution {
public:
    int f(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1<0 || j1>grid[0].size()-1 || j2<0 || j2>grid[0].size()-1) return -1e9;
        if(i<0) return 0;
        if(i==0 && (j1!=0 || j2!=grid[0].size()-1)) return dp[i][j1][j2]=-1e9;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int x=grid[i][j1];
        if(j1!=j2) x=grid[i][j1]+grid[i][j2];
        return dp[i][j1][j2]=x+max({f(i-1,j1,j2,grid,dp),f(i-1,j1,j2-1,grid,dp),f(i-1,j1,j2+1,grid,dp),f(i-1,j1-1,j2,grid,dp),f(i-1,j1-1,j2-1,grid,dp),f(i-1,j1-1,j2+1,grid,dp),f(i-1,j1+1,j2,grid,dp),f(i-1,j1+1,j2-1,grid,dp),f(i-1,j1+1,j2+1,grid,dp)});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        int maxi=INT_MIN;
        for(int j1=0;j1<grid[0].size();j1++){
            for(int j2=0;j2<grid[0].size();j2++){
                maxi=max(maxi,f(grid.size()-1,j1,j2,grid,dp));
            }
        }
        return maxi;
    }
};