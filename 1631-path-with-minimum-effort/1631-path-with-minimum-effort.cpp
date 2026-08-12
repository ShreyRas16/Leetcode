class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dist(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!pq.empty()){
            pair<int,pair<int,int>> temp=pq.top();
            pq.pop();
            for(int k=0;k<4;k++){
                int ni=temp.second.first+dx[k];
                int nj=temp.second.second+dy[k];
                if(temp.second.first==heights.size()-1 && temp.second.second==heights[0].size()-1) return temp.first;
                if(ni>=0 && nj>=0 && ni<heights.size() && nj<heights[0].size()){
                    if(dist[ni][nj]>max(temp.first,abs(heights[ni][nj]-heights[temp.second.first][temp.second.second]))){
                        dist[ni][nj]=max(temp.first,abs(heights[ni][nj]-heights[temp.second.first][temp.second.second]));
                        pq.push({dist[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        return 0;
    }
};