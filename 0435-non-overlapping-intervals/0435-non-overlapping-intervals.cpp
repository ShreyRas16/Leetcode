class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ove=0;
        vector<vector<int>> curr;
        for(int i=0;i<intervals.size();i++){
            if(curr.empty()) curr.push_back(intervals[i]);
            else{
                if(intervals[i][0]<curr[curr.size()-1][1]){
                    ove++;
                    if(intervals[i][1]<curr[curr.size()-1][1]){
                        curr.pop_back();
                        curr.push_back(intervals[i]);
                    }
                }
                else curr.push_back(intervals[i]);
            }
        }
        return ove;
    }
};