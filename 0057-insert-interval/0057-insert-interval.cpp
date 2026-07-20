class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool insert=false;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][1]<newInterval[0]) ans.push_back(intervals[i]);
            else if(!insert && intervals[i][0]>newInterval[1]){
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                insert = true;
            }
            else if(intervals[i][1]>=newInterval[0] && !insert && intervals[i][0] <= newInterval[1]){
                ans.push_back({min(intervals[i][0],newInterval[0]),max(newInterval[1],intervals[i][1])});
                insert=true;
            }
            else if(insert && ans[ans.size()-1][1]>=intervals[i][0]) ans[ans.size()-1][1]=max(intervals[i][1],ans[ans.size()-1][1]);
            else if(insert && ans[ans.size()-1][1]<intervals[i][0]) ans.push_back(intervals[i]); 
        }
        if(!insert) ans.push_back(newInterval);
        return ans;
    }
};