class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            matrix[edges[i][0]][edges[i][1]]=edges[i][2];
            matrix[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<matrix.size();i++) matrix[i][i]=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                for(int k=0;k<matrix.size();k++){
                    if(matrix[j][i]!=INT_MAX && matrix[i][k]!=INT_MAX) matrix[j][k]=min(matrix[j][k],matrix[j][i]+matrix[i][k]);
                }
            }
        }
        int mini=INT_MAX;
        int ans;
        for(int i=0;i<matrix.size();i++){
            int curr=0;
            for(int j=0;j<matrix.size();j++){
                if(matrix[i][j]<=distanceThreshold) curr++;
            }
            if(curr<=mini){
                mini=curr;
                ans=i;
            }
        }
        return ans;
    }
};